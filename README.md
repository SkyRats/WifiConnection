# WifiConection
This is a way to make a wifi connection between two or more computers. In addition, all of them can use the same master on ros, working together.

## Instructions

### Wifi Connection
  In computer1, where you want to create a wifi-hotspot, compile and run "hostspot". Then, to connect computer2 (and others, if you want), compile and run in it "connection".
  
### Ros Fusion
Now, you need to decide in which of these computers you want to run the Ros' master, in other words, to run the "roscore". That could be the same computer where you have created the hotspot, as could be other where you just have connected in wifi network.

After this choix, in every terminal where you want to run something related with ros (roscore, rostopic, rosrun, rosservice, rosmsg...), it is necessary to make a source after all. The difference between master computer and other is that in first you source "master.sh" and in others you source "client.sh" (with master's IP as first argument).

## Example
1. In computer 1
   ```  
      $ cd [where_you_cloned_the_repository]
      $ ./hotspot
   ```  
2. In computer 2:
   ```
      $ cd [where_you_cloned_the_repository]
      $ ./connection
   ```
3. I decided that computer 1 is the master.   

   * Terminal 1:  
   ```  
      $ source master.sh  
      $ roscore
   ```   
   * Terminal 2:  
   ```  
      $ source ./master.sh  
      $ rosrun turtlesim turtlesim_node
   ```  

4. In computer 2:
   ```   
      $ source ./client
      $ rostopic echo /turtle1/pose
   ```  

## Step-By-Step Option
  If this first way don't works, you can follow my daft of connection on 'StepByStepOLD.txt', where  I took notes of all the commands are needed.

## Attention
 This is a BETA, so there are a lot o problems on this sollution. For example, during my tests, I could run perfectly the programs in a direction, but, when I changed the computers 1 and 2, i couldn't connect on wifi created.
 
## 'ReferenceWifi.txt'
 Thats an initial search that I made about wifi connection. After that, I simplified the way to make the connection, but you can use it if the sollutin in 'StepByStepOLD.txt' (with exec1.sh and exec2.sh) doesn't work well.

## If you want to run the Wifi connection step by default as the system boot
    * Change the path on the `.desktop` file to the complete path of the compiled `hotspot.cpp` file
    * move the `.desktop`file to the /home/$USER/.config/autostart folder
 --- ---
 
Please write me and tell me about your experience!
 
**Ricardo C. do Lago**
(email addr: ricardodolago@gmail.com)
