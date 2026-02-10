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
UNSPECIFIED2 : 'UNSPECIFIED2';
UNSPECIFIED3 : 'UNSPECIFIED3';
UPON         : 'UPON';
VERSION      : 'VERSION';
TRUE         : 'TRUE';
FALSE        : 'FALSE';


fragment CHAR_ALPHA : [A-Z|a-z];
fragment CHAR_AF    : [A-F|a-f];
fragment CHAR_DEC   : [0-9];
fragment CHAR_OCT   : [0-7];

ID  : CHAR_ALPHA (CHAR_ALPHA | CHAR_DEC | '_')*;

NUMBER
    : CHAR_DEC+
    | CHAR_DEC+[Dd]
    | CHAR_OCT+[Bb]
    | CHAR_DEC(CHAR_DEC|CHAR_AF)*[Xx]
    ;

STR : '"' ('""' | ~('"'))* '"';

COMMENT_PARTIAL
    : '--' ~[\n\r]*? '--'      ->skip;

COMMENT_LINE
    : '--' ~[\n\r]* '\r'? '\n' ->skip;

SPACE
    : [ \r\t\n]                ->skip;


courierProgram
    :    programHeader '=' programBody '.'
    ;

programHeader
    :    name=ID ':' PROGRAM program=NUMBER VERSION version=NUMBER
    ;

programBody
    :    BEGIN dependencyList declarationList END
    ;

dependencyList
    :    /* empty */
    |    DEPENDS UPON referencedProgramList ';'
    ;

referencedProgramList
    :    elements+=referencedProgram ( ',' elements+=referencedProgram )*
    ;

referencedProgram
    :    name=ID '(' program=NUMBER ')' VERSION version=NUMBER
    ;

declarationList
    :    /* empty */
    |    elements+=declaration+
    ;

declaration
    :    name=ID ':' TYPE '=' type ';'     # DeclType
    |    name=ID ':' type '=' constant ';' # DeclCons
    ;

type
    :    predefinedType  # TypePredefined
    |    constructedType # TypeConstructed
    |    referenced      # TypeReferenced
    ;

predefinedType
    :    BOOLEAN        # TypeBoolean
    |    CARDINAL       # TypeCardinal
    |    LONG CARDINAL  # TypeLongCardinal
    |    INTEGER        # TypeInteger
    |    LONG INTEGER   # TypeLongInteger
    |    STRING         # TypeString
    |    UNSPECIFIED    # TypeUnspecified
    ;

constructedType
    :    '{' correspondenceList '}'                      # TypeEnum
    |    ARRAY numericValue OF type                      # TypeArray
    |    SEQUENCE maximumNumber OF type                  # TypeSequence
    |    RECORD '[' fieldList ']'                        # TypeRecord
    |    RECORD '[' ']'                                  # TypeRecordEmpty
    |    CHOICE referenced OF '{' typedCandidateList '}' # TypeChoiceTyped
    |    CHOICE OF '{' anonCandidateList '}'             # TypeChoiceAnon
    |    PROCEDURE argumentList resultList errorList     # TypeProcedure
    |    ERROR argumentList                              # TypeError
    ;

referenced
    :    name=ID                   # TypeRef
    |    program=ID   '.'  name=ID # TypeRefQ
    |    namespace=ID '::' name=ID # TypeRefExt
    ;

correspondenceList
    :    elements+=correspondence (',' elements+=correspondence)*
    ;

correspondence
    :    name=ID '(' value=numericValue ')'
    ;

maximumNumber
    :    /* empty */
    |    numericValue
    ;

numericValue
    :    NUMBER     # ValueNumber
    |    referenced # ValueRefCons
    ;

typedCandidateList
    :    elements+=typedCandidate (',' elements+=typedCandidate)*
    ;

typedCandidate
    :    nameList '=>' type
    ;

anonCandidateList
    :    elements+=anonCandidate (',' elements+=anonCandidate)*
    ;

anonCandidate
    :    correspondenceList '=>' type
    ;

argumentList
    :    /* empty */
    |    '[' fieldList ']'
    ;

resultList
    :    /* empty */
    |    RETURNS '[' fieldList ']'
    ;

errorList
    :    /* empty */
    |    REPORTS '[' nameList ']'
    ;

fieldList
    :    elements+=field (',' elements+=field)*
    ;

field
    :    nameList ':' type
    ;

constant
    :    literalConstant     # ConsLiteral
    |    constructedConstant # ConsConstructed
    |    referenced          # ConsRef
    ;

literalConstant
    :    TRUE             # ConsTrue
    |    FALSE            # ConsFalse
    |    value=NUMBER     # ConsNumber
    |    '-' value=NUMBER # ConsNumberNegative
    |    value=STR        # ConsString
    ;

constructedConstant
    :    '[' elementList ']'   # ConsArray
    |    '[' componentList ']' # ConsRecord
    |    '[' ']'               # ConsRecordEmpty
    |    name=ID constant      # ConsChoice
    ;

elementList
    :    elements+=constant (',' elements+=constant)*
    ;

componentList
    :    elements+=component (',' elements+=component)*
    ;

component
    :    nameList ':' constant
    ;

nameList
    :    elements+=ID (',' elements+=ID)*
    ;