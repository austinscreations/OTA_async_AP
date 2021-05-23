/* Webpage HTML - this is the reboot page */ 

#ifndef failOTA_h
#define failOTA_h

const char failOTA_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>%title% failOTA</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">

    <link rel="stylesheet" href="TheCSS.css"> 
    
    <style>
     %dark%
    </style>

  </head>

    <div id="container">

      <div id="header">
        <h2>%title% - <em>Home</em></h2>
        <div class = "menu-buttons">
          <div class = "button ButtonClickable">
            <button0 onclick="location.href='/test'">Test</button>
          </div>
          <div class = "button ButtonHere">
            <Button1 onclick="location.href='/home'">Home</button>
          </div>
          <div class = "button ButtonClickable">
            <Button2 onclick="location.href='/management'">Management</button>
          </div>
          <div class = "button ButtonClickable">
           <button3 onclick="darkFunction()">Dark Mode</button3>
          </div>
        </div>
      </div>  <!-- HEADER -->

      <div id="body">       
        <h2 align=center>Oh No!!!  It Borked!!!  What'd ya try to do?</h2>
      </div>  <!-- BODY -->

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
        </div>
      </div>  <!-- FOOTER -->
    </div>

    <script>
      function darkFunction() {
       var xhr = new XMLHttpRequest();
       xhr.open("GET", "/darkmode?state=1", true);
       xhr.send();
       setTimeout(function () {window.location.href = "/failedOTA";}, 100);
      }
   </script>
 </body>
</html>
)rawliteral";

#endif //