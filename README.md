# OTA_async_AP
Async server with OTA and AP setup built in.

2021-05-22 added new version to arduino buid - stil lahevn't merged changes to paltformIO files and vice-versa. Dark mode added and progress abr plus redirects work for OTA in teh arduino build.

2021-05-19 added folder arduino build with an arduino set up sketch that has a newer update page layout and working update % bar and confirmation redirect and then autoload home page when device reboots. this folder will end up merged with platformIO code, and newer paltformIO exists but is untested and not added yet to this repo.

2021-05-13 files sorted and catagorized and files now setup for platformIO

2021-05-11 many small changes made over the past few days. The update function does work and prints an ok on teh webpage, working on making teh update complete page look nicer. minor changes through out the past few days to fix formating and add vairables to allwo for better control of the webpage. option built in for setting device name, requires 2 lines but specific to platform.io at this moment.

2021-05-09 This is a very early setup. right now the webpage works, still need to add data to the webpage to signify esp8266 or esp32 along with device id. then adding in support for firmware update.
