# compile source code and output executable program that is client-capture
# date: 2019
# version: 1.0
# autor: g-glory-n

INCS = -I /usr/include/ -I /usr/local/include/

LIBS-all = 			\
	-L /usr/local/lib/	\
	-l:libSDL2.so		\
	-l:libx264.so		\
	-l:libx265.so		\
	-l:libavcodec.so        \
	-l:libavdevice.so       \
	-l:libavfilter.so       \
	-l:libavformat.so       \
	-l:libavutil.so         \

LIBS-SDL2 = -L /usr/local/lib/ -l:libSDL2.so

LIBS-x264 = -L /usr/local/lib/ -l:libx264.so

LIBS-x265 = -L /usr/local/lib/ -l:libx265.so

LIBS-ffmpeg = 			\
	-L /usr/local/lib/	\
	-l:libavcodec.so	\
	-l:libavdevice.so	\
	-l:libavfilter.so	\
	-l:libavformat.so	\
	-l:libavutil.so		\

PATH_CLIENT_CAPTURER = ./output/client-capturer/
PATH_SERVER_TRANSFER = ./output/server-transfer/
PATH_CLIENT_ACCEPTER = ./output/client-accepter/

none:
	@echo "\ndo nothing with no target"
	@echo "please input the format of \"make target\""
	@echo "input \"make help\" to understand the detailed information of targets\n"

help:
	@echo "\nthis is make help\n"
	
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
	@echo "begin to compile all propgram !!!"
	@echo "\n\n\n"
	make client-capturer
	@echo "\n\n\n"
	make server-transfer
	@echo "\n\n\n"
	make client-accepter
	@echo "\n\n\n"
	make clean
	@echo "\n\n\n"





client-capturer: client-capturer-v4l2.o client-capturer-SDL2.o client-capturer-x264.o client-capturer-x265.o client-capturer-ffmpeg-old.o client-capturer-network.o client-capturer-common.o client-capturer-main.o
	gcc	${PATH_CLIENT_CAPTURER}v4l2.o      \
		${PATH_CLIENT_CAPTURER}SDL2.o      \
		${PATH_CLIENT_CAPTURER}x264.o      \
		${PATH_CLIENT_CAPTURER}x265.o      \
		${PATH_CLIENT_CAPTURER}ffmpeg.old.o\
		${PATH_CLIENT_CAPTURER}udp.o       \
		${PATH_CLIENT_CAPTURER}main.o      \
		${PATH_CLIENT_CAPTURER}common.o    \
	-o	${PATH_CLIENT_CAPTURER}client-capturer ${INCS} ${LIBS-all}

client-capturer-v4l2.o: ./v4l2/v4l2.c ./v4l2/v4l2.h 
	gcc -g -c ./v4l2/v4l2.c -o ${PATH_CLIENT_CAPTURER}v4l2.o ${INCS}

client-capturer-SDL2.o: ./SDL2/client-capturer/SDL2.c ./SDL2/client-capturer/SDL2.h
	gcc -g -c ./SDL2/client-capturer/SDL2.c -o ${PATH_CLIENT_CAPTURER}SDL2.o ${INCS} ${LIBS-SDL2}
	
client-capturer-x264.o: ./x264/x264.c ./x264/x264.h
	gcc -g -c ./x264/x264.c -o ${PATH_CLIENT_CAPTURER}x264.o ${INCS} ${LIBS-x264}

client-capturer-x265.o: ./x265/x265.c ./x265/x265.h
	gcc -g -c ./x265/x265.c -o ${PATH_CLIENT_CAPTURER}x265.o ${INCS} ${LIBS-x265}

client-capturer-ffmpeg-old.o: ./ffmpeg/client-capturer/ffmpeg.old.c ./ffmpeg/client-capturer/ffmpeg.old.h
	gcc -g -c ./ffmpeg/client-capturer/ffmpeg.old.c -o ${PATH_CLIENT_CAPTURER}ffmpeg.old.o ${INCS} ${LIBS-ffmpeg}

client-capturer-network.o: ./network/client-capturer/udp/udp.c ./network/client-capturer/udp/udp.h
	gcc -g -c ./network/client-capturer/udp/udp.c -o ${PATH_CLIENT_CAPTURER}udp.o ${INCS}

client-capturer-common.o: ./common/client-capturer/common.c ./common/client-capturer/common.h
	gcc -g -c ./common/client-capturer/common.c -o ${PATH_CLIENT_CAPTURER}common.o ${INCS}

client-capturer-main.o: ./common/client-capturer/main.c
	gcc -g -c ./common/client-capturer/main.c -o ${PATH_CLIENT_CAPTURER}main.o ${INCS}





server-transfer: server-transfer-network.o server-transfer-ffmpeg-old.o server-transfer-SDL2.o server-transfer-common.o server-transfer-main.o
	gcc	${PATH_SERVER_TRANSFER}udp.o    \
		${PATH_SERVER_TRANSFER}ffmpeg.old.o \
		${PATH_SERVER_TRANSFER}SDL2.o   \
		${PATH_SERVER_TRANSFER}common.o \
		${PATH_SERVER_TRANSFER}main.o   \
	-o	${PATH_SERVER_TRANSFER}server-transfer ${INCS} ${LIBS-all}

server-transfer-network.o: 
	gcc -g -c ./network/server-transfer/udp/udp.c -o ${PATH_SERVER_TRANSFER}udp.o ${INCS}

server-transfer-ffmpeg-old.o:
	gcc -g -c ./ffmpeg/server-transfer/ffmpeg.old.c -o ${PATH_SERVER_TRANSFER}ffmpeg.old.o ${INCS} ${LIBS-ffmpeg}

server-transfer-SDL2.o:
	gcc -g -c ./SDL2/server-transfer/SDL2.c -o ${PATH_SERVER_TRANSFER}SDL2.o ${INCS} ${LIBS-SDL2}

server-transfer-common.o:
	gcc -g -c ./common/server-transfer/common.c -o ${PATH_SERVER_TRANSFER}common.o ${INCS}

server-transfer-main.o:
	gcc -g -c ./common/server-transfer/main.c -o ${PATH_SERVER_TRANSFER}main.o ${INCS}





client-accepter: client-accepter-network.o client-accepter-ffmpeg.o client-accepter-SDL2.o client-accepter-common.o client-accepter-main.o
	gcc	${PATH_CLIENT_ACCEPTER}network.o\
		${PATH_CLIENT_ACCEPTER}ffmpeg.o \
		${PATH_CLIENT_ACCEPTER}SDL2.o   \
		${PATH_CLIENT_ACCEPTER}common.o \
		${PATH_CLIENT_ACCEPTER}main.o   \
	-o	${PATH_CLIENT_ACCEPTER}client-accepter ${INCS} ${LIBS-all}

client-accepter-network.o: ./network/client-accepter/upd.c ./network/client-accepter/udp.h
	gcc -g -c ./network/client-accepter/udp/udp.c -o ${PATH_CLIENT_ACCPETER}udp.o ${INCS}

client-accepter-ffmpeg.o: ./ffmpeg/client-accepter/ffmpeg.c ./ffmpeg/client-accepter/ffmpeg.h
	gcc -g -c ./ffmpeg/client-accepter/ffmpeg.c -o ${PATH_CLIENT_ACCPETER}ffmpeg.o ${INCS} ${LIBS_ffmpeg}

client-accepter-SDL2.o: ./SDL2/client-accepter/SDL2.c ./SDL2/client-accepter/SDL2.h
	gcc -g -c ./SDL2/client-accepter/SDL2.c -o ${PATH_CLIENT_ACCPETER}SDL2.o ${INCS} ${LIBS-SDL2}

client-accepter-common.o: ./common/client-accepter/common.c ./common/client-accepter/common.h
	gcc -g -c ./common/client-accepter/common.c -o ${PATH_CLIENT_ACCPETER}common.o ${INCS}

client-accepter-main.o: ./common/client-accepter/main.c
	gcc -g -c ./common/client-accepter/main.c -o ${PATH_CLIENT_ACCPETER}main.o ${INCS}





clean:
	rm	-rf					\
		${PATH_CLIENT_CAPTURER}main.o		\
		${PATH_CLIENT_CAPTURER}common.o 	\
		${PATH_CLIENT_CAPTURER}v4l2.o   	\
		${PATH_CLIENT_CAPTURER}SDL2.o   	\
		${PATH_CLIENT_CAPTURER}x264.o   	\
		${PATH_CLIENT_CAPTURER}x265.o   	\
		${PATH_CLIENT_CAPTURER}ffmpeg.o 	\
		${PATH_CLIENT_CAPTURER}ffmpeg.old.o	\
		${PATH_CLIENT_CAPTURER}udp.o    	\
		      					\
		${PATH_SERVER_TRANSFER}udp.o    	\
		${PATH_SERVER_TRANSFER}ffmpeg.o 	\
		${PATH_SERVER_TRANSFER}ffmpeg.old.o	\
		${PATH_SERVER_TRANSFER}SDL2.o   	\
		${PATH_SERVER_TRANSFER}common.o 	\
		${PATH_SERVER_TRANSFER}main.o   	\
		      					\
		${PATH_CLIENT_ACCEPTER}udp.o    	\
		${PATH_CLIENT_ACCEPTER}ffmpeg.o 	\
		${PATH_CLIENT_ACCEPTER}SDL2.o   	\
		${PATH_CLIENT_ACCEPTER}common.o 	\
		${PATH_CLIENT_ACCEPTER}main.o   	\

distclean:
	rm	-rf					\
		${PATH_CLIENT_CAPTURER}main.o   	\
		${PATH_CLIENT_CAPTURER}common.o 	\
		${PATH_CLIENT_CAPTURER}v4l2.o   	\
		${PATH_CLIENT_CAPTURER}SDL2.o   	\
		${PATH_CLIENT_CAPTURER}x264.o   	\
		${PATH_CLIENT_CAPTURER}x265.o   	\
		${PATH_CLIENT_CAPTURER}ffmpeg.o 	\
		${PATH_CLIENT_CAPTURER}ffmpeg.old.o	\
		${PATH_CLIENT_CAPTURER}udp.o    	\
		./output/client-capturer/client-capturer\
		      					\
		${PATH_SERVER_TRANSFER}udp.o    	\
		${PATH_SERVER_TRANSFER}ffmpeg.o 	\
		${PATH_SERVER_TRANSFER}ffmpeg.old.o	\
		${PATH_SERVER_TRANSFER}SDL2.o   	\
		${PATH_SERVER_TRANSFER}common.o 	\
		${PATH_SERVER_TRANSFER}main.o   	\
		./output/server-transfer/server-transfer\
		      					\
		${PATH_CLIENT_ACCEPTER}udp.o    	\
		${PATH_CLIENT_ACCEPTER}ffmpeg.o 	\
		${PATH_CLIENT_ACCEPTER}SDL2.o   	\
		${PATH_CLIENT_ACCEPTER}common.o 	\
		${PATH_CLIENT_ACCEPTER}main.o   	\
		./output/client-accepter/client-accepter\








