/* Webpage HTML - this is the homepage*/ 

#ifndef homepage_h
#define homepage_h

const char home_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>%title% Home</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <meta http-equiv="expires" content="0">
%The_CSS%
   </head>
  <body>
  
    <div id="container">

      <div id="header">
        <h2>%title% - <em>Home</em></h2>
        <div class = "menu-buttons">
          <div class = "button ButtonHere">
            <Button1>Home</button>
          </div>
          <div class = "button ButtonClickable">
            <Button2 onclick="location.href='/config'">config</button2>
          </div>
          <div class = "button ButtonClickable">
           <button3 onclick="darkFunction()">Dark Mode</button3>
          </div>
        </div>
      </div>  <!-- HEADER -->

      <div id="body"> 

      <div class = "name-status" id="state" style="%online%">
       <span class = "name-text">ONLINE</name-text></span>
      </div>
            
        <div class = "name-host">
          <span class = "name-text">IP Address:</name-text></span>
          <span class = "host">%ipplaceholder%</host></span>
        </div>

        <div class = "name-mac">
          <span class = "name-text">MAC Address:</name-text></span>
          <span class = "host">%macplaceholder%</host></span>
        </div>
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

%The_SCRIPTS%

  </body>
</html>
)rawliteral";
#endif
