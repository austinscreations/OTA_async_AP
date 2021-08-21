/* Webpage HTML - this is the config page - lets the user set their information for the device */ 
/* Can be accessed via AP or on wifi mode */

#ifndef config_page_h
#define config_page_h

const char config_form[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>%title% Config</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <meta http-equiv="expires" content="0">
%The_CSS%
  </head>
  <body>
  
    <div id="container">

      <div id="header">
        <h2>%title% - <em>Config</em></h2>
        <div class = "menu-buttons">
          <div class = "buttons ButtonClickable">
            <Button1 onclick="location.href='/home'">Home</button1>
          </div>
          <div class = "buttons ButtonClickable">
           <button2 onclick="location.href='/management'">Management</button2>
          </div>
          <div class = "buttons ButtonHERE">
            <Button3>Config</button3>
          </div>
          <div class = "buttons ButtonClickable">
           <button4 onclick="darkFunction()">Dark Mode</button4>
          </div>
        </div>
      </div>  <!-- HEADER -->

       <div id="body"> 

       <div class = "name-status" id="state" style="%online%">
       <span class = "name-text">ONLINE</name-text></span>
      </div>

      <!--<input id="sum" name="sum" maxlength="3" type='password' placeholder="sum" value="" {c}><br/>-->

      <div class = "border">

      <form method='get' action='wifisave'>
      
      <input id='host' name='host' maxlength='31' placeholder='hostname = %IDplaceholder%'><br/>
      <input id='ssid' name='ssid' maxlength='31' placeholder='%IDssid%'><br/>
      <input id='password' name='password' maxlength='63' type='password' placeholder='%whatpass%'><br/>
      
      <br/>
   
      <input id='apssid' name='apssid' maxlength='31' placeholder='%apss%'><br/>
      <input id='appass' name='appass' maxlength='63' type='password' placeholder='%passwhat%' minlength='8'><br/>
      <input id='hidden' name='hidden' maxlength='1' placeholder='%aphid%'><br/>
      
      <br/>
      
      <input id='mqtt' name='mqtt' maxlength='31' placeholder='%broker%'><br/>
      <input id='port' name='port' maxlength='4' placeholder='%port%'><br/>
      
      <br/>
      
      <input id='mqttuser' name='mqttuser' maxlength='31' placeholder='%userID%'><br/>
      <input id='mqttpass' name='mqttpass' maxlength='31' type='password' placeholder='%notpass%'><br/>
      
      <br/>
      
      <input id='htmltitle' name='htmltitle' maxlength='31' placeholder='html title = %title%'><br/>
      <input id='htmltype' name='htmltype' maxlength='31' placeholder='html type = %type%'><br/>
      <input id='dark' name='dark' maxlength='1' placeholder='%darkmode%' ><br/>
      <input id='htmlcolor' name='htmlcolor' maxlength='7' placeholder='HTML Color' value='%color%' ><br/>
      <input id='htmlhover' name='htmlhover' maxlength='7' placeholder='HTML Hover' value='%hover%' ><br/>
      
      
      <br/><button class = "buttons ButtonClickable" type='submit'>save</button></form>
      
      </div>  <!-- Border -->
      
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
    %The_SCRIPTS%

    </script>
  </body>
</html>
)rawliteral";

#endif //
