# team-010-24-hw4

Team Member: 
Jianhao Yu (Yu000636)
Pingfan Bu (Bu007113)

What is the project about (overview of the whole project, not just the hw4)?
In this project, we simulate the delivery of packages with drones within the generated range of the University of Minnesota and its surrounding college towns. By adding various elements, we make the package delivery process similar to real-life situations. Through the simulation of different drone models, we have implemented various delivery modes. We have equipped the drones with battery systems and added charging stations to the map, enabling a drone's endurance system and charging system to make the operation of the drones more aligned with actual conditions.


How to run the simulation (overview of the whole project, not just the hw4)?
1. Go to the project directory and go to a port (port is based on what port you use such as 8081)
2. Build the project by "make -j" and then run the project by "./build/bin/transit_service 8081 apps/transit_service/web/" 
3. In a web browser, navigate to http://127.0.0.1:8081 and you should see a visualization.
4. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the delivery.



What does the simulation do specifically (individual features i.e. movement of entities etc) 
(overview of the whole project, not just the hw4)?
This simulation will simulate what a real-world drone delivery system looks like. And more specifically, it includes 1. Package delivery  2. Recharge 3 . Entities 
And moreover, the entities in our simulation include helicopters, humans, drones, robots, and packages. 
Humans: To simulate the real life scenario, humans will walk around in the city. 
Robots and Packages: These play a pivotal role. Robots represent customers who schedule the delivery of packages, which symbolize the items being transported.
Battery Feature: Adding a battery feature for drones introduces a strategic element. Drones must manage their battery life, considering their capacity for consecutive deliveries, which adds a layer of realism and planning to the simulation.


New Feature
Our group added drones wrapped around by the batteries.
And the drones will be able to find the recharge station.
And we add battery stations on the map.

What does it do?
The drone now will have battery life and when the battery goes down to a certain point, it will go for a nearest recharge station for recharging. 

Why is it significantly interesting?
Because it fits the real life scenario more, when you have a drone deliver the package, it can not just deliver one package and then go back. 

How does it add to the existing work? 
Our drone is now wrapped by batteries and can now go to recharge station

Which design pattern did you choose to implement it and why? 
The design pattern we will be using is the Decorator & Factory. The reason is that wrapping drones with batteries can be seen as adding new functionality to the drones. Battery wrap acts as a decorator, enhancing the drone's capabilities and not changing its main functionality.

Instruction to use this new feature (if the new feature is not user interactable, please mention this as well)
When you open the schedule page, you should be able to see the show battery stations. And you will be able to get all of the location of the recharge station. Drones will be able to recharge themselves after that. 

Sprint retrospective: 
## Sprint Retrospective - Month 12

### Team Members
- Jianhao Yu
- Pingfan Bu

### Contributions
Jianhao Yu:  built the battery factory and create the battery recharge 
station at the front end 
Pingfan Bu: completed the batteryDecorator part and implement the battery function

### Team-Work
- Teamwork make the project more effectively 
-  More Correct and Thought implementation of Battery Decorators.

### Challenges
- Segmentation faults 
- Stay up late cause sometimes team members' disconnect 

### Improvement
- can have more virtual connection in the future
- write code with documentation so it will make both team member easier understanding each others' code 

###Youtube Link to our project
https://www.youtube.com/watch?v=P6EmWoW0Hk8

###UML link
https://lucid.app/documents/view/fc7c6007-4bf2-472f-ac31-4eaf4c881c5a

###Docker link 
https://hub.docker.com/repository/docker/pingfan111/dronesim11/general
