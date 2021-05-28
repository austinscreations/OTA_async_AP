/* Webpage HTML - this is the update page */ 

#ifndef updatepage_h
#define updatepage_h


const char update_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html5>
<html>
  <head>
    <title>%title% Management</title>
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
        <h2>%title% - <em>Management</em></h2>
        <div class = "menu-buttons">
          <div class = "button ButtonClickable">
           <button0 onclick="location.href='/test'">Test</button>
          </div>
          <div class = "button ButtonClickable">
           <button1 onclick="location.href='/home'">Home</button>
          </div>
          <div class = "button ButtonHere">
           <button2 onclick="location.href='/management'">Management</button>
          </div>
          <div class = "button ButtonClickable">
           <button3 onclick="darkFunction()">Dark Mode</button3>
          </div>
        </div>
      </div>  <!-- HEADER -->

     <div id="body">
       <div class="col-12 mt-3 p-centered">
         <div class="col-3 col-sm-9 col-md-6 p-centered">
           <label class="label label2 mr-2">Upload Firmware Here</label>
           <div class="form-group pt-2 mt-3">
             <form method="POST" action="#" enctype="multipart/form-data" id="upload_form">
               <input type="file" name="update" id="file" accept=".bin" class="form-input file-input">
               <input type="submit" value="FLASH">
               <div class="upload-bar">
                 <div class="w3-background">
                   <div class="w3-progress" id="prg1" style="width: 0rem">
                     <span class="percent" id="prg">-</span>
                   </div>
                 </div>
               </div>
             </form>
           </div>
         </div>
       </div>

       <div class = "menu-buttons">
         <div class = "menu-reboot">
           <div class = "button ButtonClickable">
             <button4 onclick="location.href='/reboot'">%processorplaceholder% Reboot</button4>
           </div>
         </div>
       </div>

       <div class = "menu-reboot">
         <p><b>UpTime: </b>%uptime%</p>
         <p><b>Chip ID: </b>%chipid%</p>
         <p><b>Flash Size: </b>%idesize%</p>
         <p><b>Real Flash Size: :</b>%flashsize%</p>
         <p><b>SDK Version: </b>%sdkver%</p>
         <p><b>CPU Frequency: </b>%cpufreq%MHz</p>
         <p><b>Memory - Free Heap: </b>%freeheap%</p>
         <p><b>Memory - Sketch Size: </b>%memsketch%</p>
          <div class="upload-bar">
           <div class="w3-background">
             <div class="w3-progress" style="width: %memsmeter%">
             </div>
            </div>
          </div>
         <p><b>Last Reset Reason: </b>%lastreset%</p>
         <p><b>Wifi Connection: </b>%conx%</p>
         <p><b>SSID: </b>%stassid%</p>
         <p><b>IP: </b>%staip%</p>
         <p><b>MAC: </b>%stamac%</p>
         <p><b>Gateway IP: </b>%stagw%</p>
         <p><b>Subnet Mask: </b>%stasub%</p>
         <p><b>DNS IP: </b>%dnss%</p>
         <p><b>Host: </b>%hostnom%</p>
         <p><b>AP SSID: </b>%apssid%</p>
         <p><b>AP IP: </b>%apip%</p>
         <p><b>AP MAC: </b>%apmac%</p>
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

   <script>
     var domReady = function(callback) {
       document.readyState === "interactive" || document.readyState === "complete" ? callback() : document.addEventListener("DOMContentLoaded", callback);
      };

     domReady(function() {
       var myform = document.getElementById('upload_form');
       var filez  = document.getElementById('file');

       myform.onsubmit = function(event) {
         event.preventDefault();

         var formData = new FormData();
         var file     = filez.files[0];

         if (!file) { return false; }

         formData.append("files", file, file.name);

         var xhr = new XMLHttpRequest();
         xhr.upload.addEventListener("progress", function(evt) {
           if (evt.lengthComputable) {
             var per  = Math.round((evt.loaded / evt.total) * 100);
             var per1 = Math.round(per/4);
             var prg  = document.getElementById('prg');
             var prg1 = document.getElementById('prg1');

             prg1.style.width  = per1 + "rem"
             prg.innerHTML     = per + "%"
            }
          }, false);
          xhr.open('POST', location.href, true);

         // Set up a handler for when the request finishes.
         xhr.onload = function () {
           if (xhr.status === 200) {
             //alert('Success');
             window.location.href = "/complete";
            } else {
             //alert('An error occurred!');
             window.location.href = "/failedOTA";
            }
          };

         xhr.send(formData);
        }
      });

     function darkFunction() {
       var xhr = new XMLHttpRequest();
       xhr.open("GET", "/darkmode?state=1", true);
       xhr.send();
       setTimeout(function () {window.location.href = "/management";}, 100);
      }
   </script>
  </body>
</html>
)rawliteral";

#endif //
