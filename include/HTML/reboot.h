/* Webpage HTML - this is the reboot page */ 

#ifndef rebootpage_h
#define rebootpage_h

const char reboot_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>%title% Update</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <meta http-equiv="refresh" content="5; URL='/'" />

    <link rel="stylesheet" href="TheCSS.css"> 
    
    <style>
     %dark%
    </style>

  </head>
  <div id="container">

      <div id="header">
        <h2></h2>
      </div>

      <div id="body">
        <h2 align=center>Device Will Reboot and Load Home Page</h2>
      </div>

      <div id="footer">
        <div class="columns mt-10">
          <span class="label label-rounded label-blank"></span> 
          <div class="columns mt-8">
          <div class="columns mt-4">
          <div class="col-12 text-center">
            <span class="label label-rounded mr-2">%IDplaceholder%</span> 
            -
            <span class="label label-rounded label-primary ml-2">%processorplaceholder%</span>
            -
            <span class="label label-rounded mr-2">%type%</span> 
          </div>
        </div> 
        <div class="columns mt-8">
          <span class="label label-rounded label-error">%errorplaceholder%</span> 
        </div>
        </div>
      </div>  <!-- FOOTER -->
    </div>
  </body>
</html>
)rawliteral";

#endif //