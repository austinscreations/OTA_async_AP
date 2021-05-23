/* Webpage HTML - this is the donepage*/ 

#ifndef Finished_h
#define Finished_h


const char done_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>Woo Hoo!!!</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <meta http-equiv="refresh" content="5; URL='/'" />

    <link rel="stylesheet" href="TheCSS.css">

    <style>
      %dark%
    
      #midcontent {
        left: 0;
        line-height: 200px;
        margin-top: -100px;
        position: absolute;
        text-align: center;
        top: 50%;
        width: 100%;
      }
    </style>

  </head>
  <body>
    <div id="container">

      <div id="header">
        <h2>Woo Hoo!!!</h2>
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

#endif