/* Webpage HTML - this is the testpage*/ 

#ifndef testpage_h
#define testpage_h


const char *Poem PROGMEM = R"rawliteral(
<div>
<p>''Twas brillig, and the slithy toves</p>
<p>Did gyre and gimble in the wabe:</p>
<p>All mimsy were the borogoves,</p>
<p>And the mome raths outgrabe.</p>
<br>
<p>''Beware the Jabberwock, my son!</p>
<p>The jaws that bite, the claws that catch!</p>
<p>Beware the Jubjub bird, and shun</p>
<p>The frumious Bandersnatch''</p>
</div>
)rawliteral";


const char *Verkz PROGMEM = R"rawliteral(
<H2>It Bloody VERKZ!</H2>
<H1>It Actually Bloody VERKZ!</H1>
<H3>w00t</H3>

<p>I can has <s>Cheezburger</s> custom crap on a standardised web page.</p>
)rawliteral";


const char test_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>%title% Testing</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">

    <link rel="stylesheet" href="TheCSS.css">

    <style>
     %dark%
    </style>
    
  </head>
  <body>
    <div id="container">

      <div id="header">
        <h2>%title% - <em>Testing</em></h2>
        <div class = "menu-buttons">
          <div class = "button ButtonHere">
            <button0 onclick="location.href='/test'">Test</button>
          </div>
          <div class = "button ButtonClickable">
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
        %Poem%
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
       setTimeout(function () {window.location.href = "/test";}, 100);
      }
   </script>
  </body>
</html>
)rawliteral";

#endif