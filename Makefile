# compile source code and output executable program
# date: 2019
# version: 1.0
# autor: g-glory-n

PATH_CLIENT_CAPTURER=./output/client-capturer/
PATH_SERVER_TRANSFER=./output/server-transfer/
PATH_CLIENT_ACCEPTER=./output/client-accepter/

none:
	@echo "\ndo nothing with no target"
	@echo "please input the format of \"make target\""
	@echo "input \"make help\" to understand the detailed information of targets\n"

help:
	@echo "\nthis is the information of help\n"
	
	@echo "cleaning targets"
	@echo "clean:			rm *.o files"
	@echo "distclean:		rm *.o *.exe files\n"
	
	@echo "compiling targets"
	@echo "all:			compile client-capturer server-transfer client-accepter"
	@echo "client-capturer: 	compile client-capturer"
	@echo "server-transfer: 	compile server-transfer"
	@echo "client-accepter: 	compile client-accepter\n"

all:
	@echo "\n\n\n"
	@echo "begin to compile all propgram !"
	@echo "\n\n\n"
	@echo "begin to compile client-capturer !"
	@cd ./client-capturer/ && make client-capturer && cp ./output/* ../output/client-capturer/
	@echo "\n\n\n"
	@echo "begin to compile server-transfer !"
	@cd ./server-transfer/ && make server-transfer && cp ./output/* ../output/server-transfer/
	@echo "\n\n\n"
	@echo "begin to compile client-capturer !"
	@cd ./client-accepter/ && make client-accepter && cp ./output/* ../output/client-accepter/
	@echo "\n\n\n"
	@echo "compile all program successfully !"
	@echo "\n\n\n"





capturer:
	@echo "\n\n\n"
	@echo "begin to compile client-capturer !"
	@echo "\n\n\n"
	@cd ./client-capturer/ && make client-capturer && cp ./output/* ../output/client-capturer/
	@echo "compile client-capture successfully !"
	@echo "\n\n\n"





transfer:
	@echo "\n\n\n"
	@echo "begin to compile server-transfer !"
	@echo "\n\n\n"
	@cd ./server-transfer/ && make server-transfer && cp ./output/* ../output/server-transfer/
	@echo "compile server-transfer successfully !"
	@echo "\n\n\n"





accepter:
	@echo "\n\n\n"
	@echo "begin to compile client-accepter !"
	@echo "\n\n\n"
	@cd ./client-accepter/ && make client-accepter && cp ./output/* ../output/client-accepter/
	@echo "compile client-accepter successfully !"
	@echo "\n\n\n"





clean:
	@cd ./client-capturer/ && make clean
	@cd ./server-transfer/ && make clean
	@cd ./client-accepter/ && make clean
	rm	-rf					\
		${PATH_CLIENT_CAPTURER}*.o		\
							\
		${PATH_SERVER_TRANSFER}*.o		\
							\
		${PATH_CLIENT_ACCEPTER}*.o		\





distclean:
	@cd ./client-capturer/ && make distclean
	@cd ./server-transfer/ && make distclean
	@cd ./client-accepter/ && make distclean
	rm	-rf					\
		${PATH_CLIENT_CAPTURER}*		\
							\
		${PATH_SERVER_TRANSFER}*		\
							\
		${PATH_CLIENT_ACCEPTER}*		\





