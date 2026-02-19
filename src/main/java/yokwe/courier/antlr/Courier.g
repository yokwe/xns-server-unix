/*******************************************************************************
 * Copyright (c) 2026, Yasuhiro Hasegawa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

grammar Courier;

ARRAY        : 'ARRAY';
BEGIN        : 'BEGIN';
BOOLEAN      : 'BOOLEAN';
CARDINAL     : 'CARDINAL';
CHOICE       : 'CHOICE';
DEPENDS      : 'DEPENDS';
DEPENDENT    : 'DEPENDENT';
END          : 'END';
ERROR        : 'ERROR';
INTEGER      : 'INTEGER';
LONG         : 'LONG';
MACHINE      : 'MACHINE';
OF           : 'OF';
PROCEDURE    : 'PROCEDURE';
PROGRAM      : 'PROGRAM';
RECORD       : 'RECORD';
REPORTS      : 'REPORTS';
RETURNS      : 'RETURNS';
SEQUENCE     : 'SEQUENCE';
STRING       : 'STRING';
TYPE         : 'TYPE';
UNSPECIFIED  : 'UNSPECIFIED';
UPON         : 'UPON';
VERSION      : 'VERSION';
TRUE         : 'TRUE';
FALSE        : 'FALSE';


fragment CHAR_ALPHA : [A-Z|a-z];
fragment CHAR_AF    : [A-F|a-f];
fragment CHAR_DEC   : [0-9];
fragment CHAR_OCT   : [0-7];

NUMBER
    : CHAR_DEC+
    | CHAR_DEC+[D]
    | CHAR_OCT+[B]
    | (CHAR_DEC|CHAR_AF)+[H]
    ;

ID  : CHAR_ALPHA (CHAR_ALPHA | CHAR_DEC | '_')*;

STR : '"' ('""' | ~('"'))* '"';

COMMENT_PARTIAL
    : '--' ~[\n\r]*? '--'      ->skip;

COMMENT_LINE
    : '--' ~[\n\r]* '\r'? '\n' ->skip;

SPACE
    : [ \r\t\n]                ->skip;



/* 4.2 Program declarations */
courierProgram
    :    name=ID ':' PROGRAM program=positiveNumber VERSION version=positiveNumber
         '=' BEGIN dependencyList declarationList END '.'
    ;

dependencyList
    :    /* EMPTY */
    |    DEPENDS UPON referencedProgramList ';'
    ;

referencedProgramList
    :    elements+=referencedProgram ( ',' elements+=referencedProgram )*
    ;

referencedProgram
    :    name=ID '(' program=positiveNumber ')' VERSION version=positiveNumber
    ;

declarationList
    :    /* EMPTY */
    |    elements+=declaration+
    ;

declaration
    :    typeDecl # DeclarationType
    |    consDecl # DeclarationCons
    ;


/* 3.3 Type and constant declarations */
typeDecl
    :    name=ID ':' TYPE '=' type ';'
    ;

consDecl
    :    name=ID ':' type '=' cons ';'
    ;

type
    :    booleanType      # TypeBoolean
    |    cardinalType     # TypeCardinal
    |    longCardinalType # TypeLongCardinal
    |    integerType      # TypeInteger
    |    longIntegerType  # TypeLongInteger
    |    stringType       # TypeString
    |    unspecifiedType  # TypeUnspecified
    /**/
    |    enumerationType  # TypeEnumeration
    |    arrayType        # TypeArray
    |    sequenceType     # TypeSequence
    |    recordType       # TypeRecord
    |    choiceType       # TypeChoice
    |    procedureType    # TypeProcedure
    |    errorType        # TypeError
    /**/
    |    reference        # TypeReference
    ;

cons
    :    booleanConstant  # ConsBoolean
    |    positiveNumber   # ConsPositive
    |    negativeNumber   # ConsNegative
    |    stringConstant   # ConsString
    /**/
    |    arrayConstant    # ConsArray
    |    recordConstant   # ConsRecord
    |    choiceConstant   # ConsChoice
    /**/
    |    reference        # ConsReference
    ;
    
reference
    :    name=ID                 # ReferenceLocal
    |    program=ID '.'  name=ID # ReferenceRemote
    |    program=ID '::' name=ID # ReferenceExternal
    ;

/* 3.4 Predefiend types */
positiveNumber
    :    NUMBER
    ;

negativeNumber
    :    '-' NUMBER
    ;

/* 3.4.1 Boolean */
booleanType
    :    BOOLEAN
    ;

booleanConstant
    :    TRUE  # BooleanConstantTrue
    |    FALSE # BooleanConstantFalse
    ;

/* 3.4.2 Cardinal */
cardinalType
    :    CARDINAL
    ;

/* 3.4.3 Long cardinal */
longCardinalType
    :    LONG CARDINAL
    ;

/* 3.4.4 Integer */
integerType
    :    INTEGER
    ;

/* 3.4.5 Long integer */
longIntegerType
    :    LONG INTEGER
    ;

/* 3.4.6 String */
stringType
    :    STRING
    ;
    
stringConstant
    :    STR
    ;

/* 3.4.7 Unspecified */
unspecifiedType
    :    UNSPECIFIED
    ;

/* 3.5.1 Enumeration */
enumerationType
    :    '{' correspondenceList '}'
    ;
    
enumerationConstant
    :    name=ID
    ;

correspondenceList
    :    elements+=correspondence (',' elements+=correspondence)*
    ;
correspondence
    :    name=ID '(' number=positiveNumber ')'
    ;

/* 3.5.2 Array */
arrayType
    :    ARRAY positiveNumber OF type # ArrayTypeNumber
    ;

arrayConstant
    :    '[' elementList ']' # ArrayConstantList
    |    '[' ']'             # ArrayConstantEmpty
    ;

elementList
    :    elements+=cons  (',' elements+=cons)*
    ;

/* 3.5.3 Sequence */
sequenceType
    :    SEQUENCE /* EMPTY */    OF type # SequenceTypeEmpty
    |    SEQUENCE positiveNumber OF type # SequenceTypeNumber
    ;

/* 3.5.4 Record */
recordType
    :    RECORD '[' /* EMPTY */ ']' # RecordTypeEmpty
    |    RECORD '[' fieldList   ']' # RecordTypeList
    ;

recordConstant
    :    '[' /* EMPTY */   ']' # RecordConstantEmpty
    |    '[' componentList ']' # RecordConstantList
    ;

fieldList
    :    elements+=field (',' elements+=field)*
    ;

field
    :    nameList ':' type
    ;

componentList
    :   elements+=component (',' elements+=component)*
    ;

component
    :    nameList ':' cons
    ;
    
nameList
    :    elements+=ID (',' elements+=ID)*
    ;
    
/* 3.5.5 Choice */
choiceType
    :    CHOICE /* EMPTY */ OF '{' candidateList     '}' # ChoiceTypeAnon
    |    CHOICE reference   OF '{' candidateNameList '}' # ChoiceTypeName
    ;

choiceConstant
    :    name=ID cons
    ;

candidateList
    :    elements+=candidate  (',' elements+=candidate)*
    ;

candidate
    :    designatorList '=>' type
    ;

designatorList
    :    elements+=designator  (',' elements+=designator)*
    ;

designator
    :    name=ID '(' number=positiveNumber ')'
    ;

candidateNameList
    :    elements+=candidateName  (',' elements+=candidateName)*
    ;
candidateName
    :    nameList '=>' type
    ;

/* 3.5.6 Procedure */
procedureType
    :    PROCEDURE argumentList resultList errorList
    ;

argumentList
    :    /* EMPTY */
    |    '[' fieldList ']'
    ;

resultList
    :    /* EMPTY */
    |    RETURNS '[' fieldList ']'
    ;

errorList
    :    /* EMPTY */
    |    REPORTS '[' nameList ']'
    ;

/* 3.5.7 Error */
errorType
    :    ERROR argumentList
    ;
