# compile source code and output executable program that is server-transfer
# date: 2019
# version: 1.0
# autor: g-glory-n

INCS = -I /usr/include/ -I /usr/local/include/

LIBS-shared-all =               \
				\
	-L /usr/local/lib/      \
	-l:libjrtp.so           \
				\
	-L /usr/local/lib/      \
	-l:libx264.so           \
	                        \
	-L /usr/local/lib/      \
	-l:libx265.so           \
	                        \
	-L /usr/local/lib/      \
	-l:libavcodec.so        \
	-l:libavdevice.so       \
	-l:libavfilter.so       \
	-l:libavformat.so       \
	-l:libavutil.so         \
	                        \
	-L /usr/local/lib/      \
	-l:libSDL2.so           \


LIBS-static-all = 		\
	-L /usr/local/lib/	\
	-l:libSDL2.so		\
	-l:libx264.so		\
	-l:libx265.so		\
	-l:libavcodec.so        \
	-l:libavdevice.so       \
	-l:libavfilter.so       \
	-l:libavformat.so       \
	-l:libavutil.so         \

LIBS-shared-SDL2 = -L /usr/local/lib/ -l:libSDL2.so

LIBS-shared-x264 = -L /usr/local/lib/ -l:libx264.so

LIBS-shared-x265 = -L /usr/local/lib/ -l:libx265.so

LIBS-shared-ffmpeg = 			\
	-L /usr/local/lib/	\
	-l:libavcodec.so	\
	-l:libavdevice.so	\
	-l:libavfilter.so	\
	-l:libavformat.so	\
	-l:libavutil.so		\

PATH_SERVER_TRANSFER = ./output/

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
	@echo "server-transfer: 	compile server-transfer\n"





server-transfer: 					\
			server-transfer-tcp.o		\
			server-transfer-udp.o	 	\
							\
			server-transfer-ffmpeg-old.o 	\
							\
			server-transfer-SDL2.o 		\
							\
			server-transfer-common.o 	\
			server-transfer-main.o 		\
							\
							\
			server-transfer-v4l2.o		\

	gcc	${PATH_SERVER_TRANSFER}tcp.o        \
		${PATH_SERVER_TRANSFER}udp.o        \
		${PATH_SERVER_TRANSFER}ffmpeg.old.o \
		${PATH_SERVER_TRANSFER}SDL2.o       \
		${PATH_SERVER_TRANSFER}common.o     \
		${PATH_SERVER_TRANSFER}main.o       \
		${PATH_SERVER_TRANSFER}v4l2.o       \
	-o	${PATH_SERVER_TRANSFER}server-transfer ${INCS} ${LIBS-shared-all}

server-transfer-tcp.o: ./network/tcp/tcp.c ./network/tcp/tcp.h
	gcc -g -c ./network/tcp/tcp.c -o ${PATH_SERVER_TRANSFER}tcp.o ${INCS}

server-transfer-udp.o: ./network/udp/udp.c ./network/udp/udp.h
	gcc -g -c ./network/udp/udp.c -o ${PATH_SERVER_TRANSFER}udp.o ${INCS}

server-transfer-ffmpeg-old.o: ./ffmpeg/ffmpeg.old.c ./ffmpeg/ffmpeg.old.h
	gcc -g -c ./ffmpeg/ffmpeg.old.c -o ${PATH_SERVER_TRANSFER}ffmpeg.old.o ${INCS} ${LIBS-shared-ffmpeg}

server-transfer-SDL2.o: ./SDL2/SDL2.c ./SDL2/SDL2.h
	gcc -g -c ./SDL2/SDL2.c -o ${PATH_SERVER_TRANSFER}SDL2.o ${INCS} ${LIBS-shared-SDL2}

server-transfer-common.o: ./common/common.c ./common/common.h
	gcc -g -c ./common/common.c -o ${PATH_SERVER_TRANSFER}common.o ${INCS}

server-transfer-main.o: ./common/main.c
	gcc -g -c ./common/main.c -o ${PATH_SERVER_TRANSFER}main.o ${INCS}



server-transfer-v4l2.o: ./v4l2/v4l2.c ./v4l2/v4l2.h
	gcc -g -c ./v4l2/v4l2.c -o ${PATH_SERVER_TRANSFER}v4l2.o ${INCS}





clean:
	rm -rf ${PATH_SERVER_TRANSFER}*.o

distclean:
	rm -rf ${PATH_SERVER_TRANSFER}*




