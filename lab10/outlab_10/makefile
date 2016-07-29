compile:
	@javac src/cs251lab10package/ClientEnc.java src/cs251lab10package/Encryptor.java src/cs251lab10package/JChatComm.java src/cs251lab10package/JClient.java src/cs251lab10package/JMessage.java src/cs251lab10package/JPacket.java src/cs251lab10package/JServer.java
	@mkdir -p bin/cs251lab10package 
	@mv src/cs251lab10package/*.class bin/cs251lab10package

clean:
	@rm -rf bin

startClient:
	@cd bin; \
	java cs251lab10package.JClient

startServer:
	@cd bin; \
	java cs251lab10package.JServer
