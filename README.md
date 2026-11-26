# CanComBi
An application to permit the user to write CAN and CAN-FD sequences.

# Capability
- The application must be able to transmit and receive CAN and CAN-FD messages.
- The application must be able to run sequences defined in text files, and parse those files to be sure the sequence is valid.
- The application may add utilities to make decisions based on the results from received messages.

# Structure
- CanStream: This entity makes all decisions based on information received from other components. It receives string data and converts it into something useful. It should also be able to detect and flag issues when one of the communicators sends it "tester present" which should normally not be received here.
- FileParser: This entity reads in lines from the program file, converts them to strings, and sends them to the CanStream. It should also detect invalid strings (0xAR is invalid hex, for example) and substitute them for "tester present." It should also correct string formatting (the string "BADBEEF" gets turned into "0B AD BE EF" for example).
- VehicleCommunicator: This entity does the same activity as the FileParser, but will receive it's data from the vehicle instead of from the program file. It is expected to do all the same detection and correction as the FileParser. It should also be able to send configurable time-based tester present signals to the vehicle.