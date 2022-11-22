Project ARGO is my brain child which has been inspired by the issues nears our college regarding to movement and transportation as my college is located in outskirts and has poor connectivity in terms of cabs or in general mean of transport. This project brings the seller's of rental vehicles at one place and also in future will allow students/teachers to avail facilty like pooling as well.
Project ARGO is divided into two phases. The first phase is testing the phase on local computer that takes in the input from the user, stores it in a databse, matches the availability and other details from the inventory and provides the location of nearest seller to the customer.
Second phase focuses on building a complete website for users to book their rental vehicles, have a pooling ride etc.

First Phase

Main.cpp contains the C++ code used to link C++ and MySQL according to the database and the table that I have created for storing the data;
On executing the C++ code, the seller can enter the details by checking it from the inventory table to ensure if the given vehicle is available or not.
All of this data is stored inside a table which is stored in a centralised database called minproj in my case.

Image below showcases how a customer will be able to see the nearest seller or in future the nearest avialble pool ride. This has been created using folium in python that takes in the latitude and longitude of the location to plot the location of customer and seller.

![Map](https://user-images.githubusercontent.com/73575537/203420799-b800a28b-2707-4f34-a46c-218b57d8d8cd.JPG)


Image below showcases the window that is used by the seller. I have randomly added some values in it.

![ARGO1](https://user-images.githubusercontent.com/73575537/197339130-228213a6-4f38-47c4-84bc-446ae191284f.JPG)

The next image showcases two tables, one is the table named MAIN_SERVER that stores details from every seller and the second one is called INVENTORY that updates the status of each seller's shop. 

![image](https://user-images.githubusercontent.com/73575537/197339213-0b4391ac-817d-4f9b-ab0d-3d33b6dde547.png)

![image](https://user-images.githubusercontent.com/73575537/197339229-ce6b625d-5291-46b4-a942-2688e2c4904b.png)



Second Phase - In Process

