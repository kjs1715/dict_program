all:
	g++ -o main Main.cpp Database.cpp Myless.cpp WordNode.cpp NewFrame.cpp Funcbase.cpp Graph.cpp Referdic.cpp Viewfunc.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp tinystr.cpp jiyi.cpp ManageWords.cpp Client.cpp -g
clean:
	rm main
