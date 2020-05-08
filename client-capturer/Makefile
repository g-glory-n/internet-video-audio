# compile source code and output executable program that is client-capture
# date: 2019
# version: 1.0
# autor: g-glory-n



INCS-v4l2 = -I /usr/include/ -I /usr/local/include/ -I ./v4l2/include/
INCS-SDL2 = -I /usr/include/ -I /usr/local/include/ -I ./SDL2/include/
INCS-x264 = -I /usr/include/ -I /usr/local/include/ -I ./x264/include/
INCS-x265 = -I /usr/include/ -I /usr/local/include/ -I ./x265/include/
INCS-ffmpeg = -I /usr/include/ -I /usr/local/include/ -I ./ffmpeg/include/
INCS-rtp = -I /usr/include/ -I /usr/local/include/ -I ./network/rtp/include/
INCS-udp = -I /usr/include/ -I /usr/local/include/ -I ./network/udp/include/
INCS-common = -I /usr/include/ -I /usr/local/include/ -I ./common/include/
INCS-main = -I /usr/include/ -I /usr/local/include/ -I ./common/include/




LIBS-shared-all = 		\
				\
	-L /usr/local/lib/	\
	-l:libx264.so		\
				\
	-L /usr/local/lib/	\
	-l:libx265.so		\
				\
	-L /usr/local/lib/	\
	-l:libavcodec.so        \
	-l:libavdevice.so       \
	-l:libavfilter.so       \
	-l:libavformat.so       \
	-l:libavutil.so         \
				\
				\
	-L /usr/local/lib/	\
	-l:libjrtp.so		\
				\
				\
	-L /usr/local/lib/	\
	-l:libSDL2.so		\


LIBS-shared-SDL2 = -L /usr/local/lib/ -l:libSDL2.so

LIBS-shared-x264 = -L /usr/local/lib/ -l:libx264.so

LIBS-shared-x265 = -L /usr/local/lib/ -l:libx265.so

LIBS-shared-ffmpeg = 		\
	-L /usr/local/lib/	\
	-l:libavcodec.so	\
	-l:libavdevice.so	\
	-l:libavfilter.so	\
	-l:libavformat.so	\
	-l:libavutil.so		\

LIBS-shared-rtp = -L /usr/local/lib/ -l:libjrtp.so










LIBS-static-all =		\
	-L ./x264/lib/		\
	-l:libx264.a		\
				\
	-L ./x265/lib/		\
	-l:libx265.a		\
				\
	-L ./ffmppeg/lib/	\
	-l:libavcodec.a		\
	-l:libavdevice.a	\
	-l:libavfilter.a	\
	-l:libavformat.a	\
	-l:libavutil.a		\
				\
	-L ./SDL2/lib/		\
	-l:libSDL2.a		\
				\
	-L ./network/rtp/lib/	\
	-l:libjrtp.a		\


LIBS-static-x264 = 		\
	-L ./x264/lib/ 		\
	-l:libx264.a		\

LIBS-static-x265 = 		\
	-L ./x265/lib/		\
       	-l:libx265.a		\

LIBS-static-ffmpeg = 		\
	-L ./ffmpeg/lib/ 	\
	-l:libavcodec.a		\
	-l:libavdevice.a        \
	-l:libavfilter.a        \
	-l:libavformat.a        \
	-l:libavutil.a          \

LIBS-static-SDL2 = 		\
	-L ./SDL2/lib/		\
	-l:libSDL2.a		\

LIBS-static-rtp = -L ./network/rtp/lib/ -l:libjrtp.a










PATH_CLIENT_CAPTURER = ./output/



#default:
#	@echo "\n\n\n"
#	@echo "begin to compile the client-capturer !"
#	@echo "\n\n\n"
#	make client-capturer
#	@echo "\n\n\n"
#	@echo "compile the client-capturer successfully !"
#	@echo "\n\n\n"





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
	@echo "client-capturer: 	compile client-capturer\n"





client-capturer:	client-capturer-v4l2.o		\
							\
			client-capturer-x264.o 		\
			client-capturer-x265.o 		\
			client-capturer-ffmpeg-old.o 	\
							\
			client-capturer-tcp.o		\
			client-capturer-udp.o 		\
			client-capturer-jrtp.o		\
			client-capturer-network.o	\
							\
			client-capturer-common.o 	\
			client-capturer-main.o		\
							\
							\
			client-capturer-SDL2.o 		\

	g++	${PATH_CLIENT_CAPTURER}v4l2.o      \
		${PATH_CLIENT_CAPTURER}x264.o      \
		${PATH_CLIENT_CAPTURER}x265.o      \
		${PATH_CLIENT_CAPTURER}ffmpeg.old.o\
		${PATH_CLIENT_CAPTURER}tcp.o       \
		${PATH_CLIENT_CAPTURER}udp.o       \
		${PATH_CLIENT_CAPTURER}jrtp.o       \
		${PATH_CLIENT_CAPTURER}main.o      \
		${PATH_CLIENT_CAPTURER}common.o    \
		${PATH_CLIENT_CAPTURER}SDL2.o      \
	-o	${PATH_CLIENT_CAPTURER}client-capturer ${LIBS-shared-all}

client-capturer-v4l2.o: ./v4l2/v4l2.c ./v4l2/v4l2.h 
	gcc -g -c ./v4l2/v4l2.c -o ${PATH_CLIENT_CAPTURER}v4l2.o ${INCS-v4l2}



client-capturer-x264.o: ./x264/x264.c ./x264/x264.h
	gcc -g -c ./x264/x264.c -o ${PATH_CLIENT_CAPTURER}x264.o ${INCS-x264} ${LIBS-shared-x264}

client-capturer-x265.o: ./x265/x265.c ./x265/x265.h
	gcc -g -c ./x265/x265.c -o ${PATH_CLIENT_CAPTURER}x265.o ${INCS-x265} ${LIBS-shared-x265}

client-capturer-ffmpeg-old.o: ./ffmpeg/ffmpeg.old.c ./ffmpeg/ffmpeg.old.h
	gcc -g -c ./ffmpeg/ffmpeg.old.c -o ${PATH_CLIENT_CAPTURER}ffmpeg.old.o ${INCS-ffmpeg} ${LIBS-shared-ffmpeg}



client-capturer-tcp.o: ./network/tcp/tcp.c ./network/tcp/tcp.h
	gcc -g -c ./network/tcp/tcp.c -o ${PATH_CLIENT_CAPTURER}tcp.o ${INCS-tcp}

client-capturer-udp.o: ./network/udp/udp.c ./network/udp/udp.h
	gcc -g -c ./network/udp/udp.c -o ${PATH_CLIENT_CAPTURER}udp.o ${INCS-udp}

client-capturer-jrtp.o: ./network/rtp-jrtp/jrtp.cpp ./network/rtp-jrtp/jrtp.h
	g++ -g -c ./network/rtp-jrtp/jrtp.cpp -o ${PATH_CLIENT_CAPTURER}jrtp.o ${INCS-rtp} ${LIBS-shared-rtp}

client-capturer-network.o:



client-capturer-common.o: ./common/common.c ./common/common.h
	gcc -g -c ./common/common.c -o ${PATH_CLIENT_CAPTURER}common.o ${INCS-common}

client-capturer-main.o: ./common/main.c
	gcc -g -c ./common/main.c -o ${PATH_CLIENT_CAPTURER}main.o ${INCS-main}





client-capturer-SDL2.o: ./SDL2/SDL2.c ./SDL2/SDL2.h
	g++ -g -c ./SDL2/SDL2.c -o ${PATH_CLIENT_CAPTURER}SDL2.o ${INCS-SDL2} ${LIBS-shared-SDL2}





clean:
	rm -rf ${PATH_CLIENT_CAPTURER}*.o

distclean:
	rm -rf ${PATH_CLIENT_CAPTURER}*



