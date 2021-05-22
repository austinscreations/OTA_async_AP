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

</body>
</html>
)rawliteral";

#endif //