source: https://www.hackster.io/dmitrywat/rgb-d-slam-with-kinect-on-raspberry-pi-4-ros-melodic-ace795

---

**try**
 * Lubuntu
 * Ubuntu Server with i3 tiling window manager
   * https://github.com/thexavier666/i3_ubuntu_server

---

### First Impressions

* This is not up to date
* I am running Ubuntu 24 and the above source calls for Ubuntu 20.04
* The source above refereneces materials that might also be out of date and not work with this version of Ubuntu
* I need to dive more into their continued support of their products or if they are EOL

### Mentioned Materials

* Kinect drivers
* RTAB-MAP ROS
* ROS Noetic

### Kinect Information

* Libfreenext: https://github.com/OpenKinect/libfreenect
  * Only use for Kinect V1
  * If Kinect V2, then use Libfreenect2
 
# Experience

* Ubuntu server is working much better
* Cmake and Libusb installed first time
* I prefer server interface, much more user friendly and palatable
* server interface does not have a gui or a window manager
 * this means that all my work up until this point is wrong and i have to restart - i've tried installing a gui but it locked the boot up sequence
 * 
