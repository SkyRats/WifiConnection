# WifiConnection
This is a way to make a wifi connection between two or more computers. In addition, all of them can use the same master on ros, working together.

## First of All
   **(Actions to be done once in each computer used during theese process...)**
   
   To start using theese tools, it's necessary to make a `git clone`. So:
```
   $ cd ~/
   $ git clone https://github.com/SkyRats/WifiConnection
```
   Then, you need to compile the sources files to generate our tools:
```
   $ cd ~/WifiConnection
   $ chmod +x firstofall.sh
   $ ./firstofall.sh
```   

## Instructions

### Wifi Connection
  In **computer1**, where you want to create a wifi-hotspot, if it is the first time, run ```newhostspot```:

   > Note: Truely the command is ```$ ./newhotspot```. As well as the next times I'll say `run`.

   I've inserted in codes a line to create the hotspot automaticaly, every time you turn on the computer (because this would help us using it in drones.)

   If you mant to turn on the hotspot, but it isn't the firts time in **computer1**, run ```reusing```.
  
   Then, to connect **computer2** (and others, if you want) on the network created, run ```connection``` in each os then.
   
   #### Using automaticaly `reusing`
   If, because of some reason that i cant understad, the hotspot is not been created when you turn on the computer, but it works when you run `reusing`, you can configure it on system to force runing `reusing` when you turn on the computer:
   * Check if the path of ```reusing``` file is correct on ```.desktop```
   * Move the ```.desktop``` file to the /home/$USER/.config/autostart folder

### SSH accessing

   If you want to do something in the other computer, for example you are in **computer2** and you want to run a code in **computer1**, you can use SSH.

  Number one, check if in both computer there is `ssh` installed:
```
   $ which ssh
```
   Number two, check if the both computers are connected at the same network:
```
   $ ping [IP_OF_THE_OTHER_COMPUTER]
```
   > Note: If the other computer is the hotspot that we've created before, probably its IP will be 10.42.0.1.

   Number three, access the other computer with SSH:
```
   $ ssh -X [USER]@[IP]
```
   (both informations are from the other computer that we want to access)


### Ros Fusion
Now, you need to decide in which of these computers you want to run the Ros' master, in other words, to run the ```roscore```. That could be the same computer where you have created the hotspot, as could be other where you just have connected in wifi network.

After this choix, in every terminal where you want to run something related with ros (```roscore```, ```rostopic```, ```rosrun```, ```rosservice```, ```rosmsg```...), it is necessary to make a source before all. The difference between master computer and the others is that in first you source ```master.sh``` and in others you source ```client.sh``` (with master's IP as first argument).

## Example
(**After the `First of All` step in both computers**...)

1. In computer 1
```  
   $ cd ~/WifiConnection
   $ ./newhotspot
```  
2. In computer 2:
```
   $ cd ~/WifiConnection
   $ ./connection
```

3. I decided that computer 1 is the master.   

   * Terminal 1:  
   ```  
      $ cd ~/WifiConnection
      $ source master.sh  
      $ roscore
   ```   
   * Terminal 2:  
   ```  
      $ cd ~/WifiConnection
      $ source ./master.sh  
      $ rosrun turtlesim turtlesim_node
   ```  

4. In computer 2:
```   
   $ cd ~/WifiConnection
   $ source ./client.sh
   $ rostopic echo /turtle1/pose
```  

## Old Option
  If this first way don't works, you can follow my daft of connection on ```old/StepByStepOLD.txt```, where I took notes of all the commands are needed. 
  > Note: It is nice to use together `ZolubasObservation/observation.md`
 
## Veryold Option
 `ReferenceWifi.txt` is an initial search that I made about wifi connection. After that, I simplified the way to make the connection, but you can use it if the sollution in 'StepByStepOLD.txt' (with ```exec1.sh``` and ```exec2.sh```) doesn't work well.
 
## Attention
 This is a BETA, so there are a lot o problems on this sollution. For example, during my tests, I could run perfectly the programs in a direction, but, when I changed the computers 1 and 2, i couldn't connect on wifi created.
 --- ---
Please write to me and tell me about your experience!
 
**Ricardo C. do Lago** (email addr: ricardodolago@gmail.com)
