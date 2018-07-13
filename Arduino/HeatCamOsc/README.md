Output of the heatcam system will consist of 8 OSC messages with the address "/camera/x" where x is the row of the matrix [0-7].  
Each message contains 8 ints representing the tempature the camera sees.

I wanted to put all 64 values in one messate, but the Arduino crashed after 10 ints were put in a message.  I think there is a memory issue.

Heres the output using my test python program that dumps all messsges it is send.
'''
Path is:  /camera/0  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/1  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/2  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/3  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/4  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/5  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/6  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
Path is:  /camera/7  Tags is:  iiiiiiii  Args are:  [0, 1, 2, 3, 4, 5, 6, 7]  Source is:  ('192.168.0.103', 1025)
'''
I have not decided on the frequency here yet.  Will see what works with server and animations.
