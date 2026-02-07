#
# Makefile
#

BUILD_DIR  := build
SOURCE_DIR := src
DATA_DIR   := data
MAVEN_BUILD_DIR := target

ANTLR_DIR := src/main/java/yokwe/gen_stub/courier/antlr

export BUILD_DIR

LOG4CXX_CONFIGURATION := data/log4j-config.xml
export LOG4CXX_CONFIGURATION


.PHONY: all clean help cmake build distclean distclean-cmake distclean-macos

all:
	@echo "BUILD_DIR             ${BUILD_DIR}"
	@echo "SOURCE_DIR            ${SOURCE_DIR}"
	@echo "LOG4CXX_CONFIGURATION ${LOG4CXX_CONFIGURATION}"

#
# cmake related targets
#
clean:
	cmake --build ${BUILD_DIR} --target clean

help:
	cmake --build ${BUILD_DIR} --target help

cmake: distclean-cmake
	mkdir -p ${BUILD_DIR}; cd ${BUILD_DIR}; cmake ../${SOURCE_DIR} -G Ninja

build:
	/usr/bin/time cmake --build ${BUILD_DIR}

distclean: distclean-cmake distclean-maven distclean-macos

distclean-cmake:
	rm -rf ${BUILD_DIR}

distclean-maven:
	rm -rf ${MAVEN_BUILD_DIR}

distclean-macos:
	find . -type f -name '._*' -print -delete
	
server:
	/usr/bin/time cmake --build build --target server

tcpdump-xns:
	sudo tcpdump ether proto 0x0600

#
# ANTLR
#
clean-antr:
	rm -f $(ANTLR_DIR)/*.java

build-antlr: $(ANTLR_DIR)/CourierParser.java
	mvn ant:ant install

$(ANTLR_DIR)/CourierParser.java: $(ANTLR_DIR)/Courier.g
	mkdir -p tmp/antlr
	rm   -rf tmp/antlr/*
	ant antlr-v4-tool
	rm   -f $(ANTLR_DIR)/*.java
	cp   -p  tmp/antlr/$(ANTLR_DIR)/*.java $(ANTLR_DIR)

gen-stub:
#	rm   -rf src/courier-stub/*.{cpp,h}
	ant gen-stub

build-java:
	mvn ant:ant install

#
# run-XXX
#
prepare-log:
	mkdir -p ${BUILD_DIR}/run
	/bin/echo -n >${BUILD_DIR}/run/debug.log

run-server: server
	mkdir -p ${BUILD_DIR}/run
	/bin/echo -n >${BUILD_DIR}/run/server.log
	LOG4CXX_CONFIGURATION=data/log4j-config-server.xml ${BUILD_DIR}/server/server
