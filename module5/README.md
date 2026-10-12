Problem Statement
A client that connects with servers and makes a request for a file to the server and server that accepts file name and sends back its content. The code handles error conditions like invalid file name, file not found, or file size exceeds the allowed limit.

Describe the Solution
The server creates a socket and binds it to port 9001 and waits for a client to connect. Once it connects the server receives a file name then checks that the name is valid then tries to open the file. Of it cant open it sends an error that the file isn't found. If it opens the server reads up to 2049 characters and if it gets to 2049 then its over the limit so it sends the exceeds limit error. Or it just sends the file to the client if everything is in bounds then the server exits. The client creates a socket and connects to the server on port 9001. It asks the user to type a file name and sends it to the server and prints what the server sends back like file content or error message.

Pros and Cons of your solution 
Pros: Got to see how netoworking works and first hand of client and server requests.
Cons: The server only handles one request then exits.
