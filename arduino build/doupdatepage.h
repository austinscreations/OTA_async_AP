/* Webpage HTML - future spot for a page that shows update progress. */ 

#ifndef doupdatepage_h
#define doupdatepage_h

const char reboot_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
<title>%title% reboot worked</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <meta http-equiv="refresh" content="5; URL='/'" />
</head>
<body>
</script>
</body>
</html>

)rawliteral";
  

const char test2_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
<title>%title% worked</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <meta http-equiv="refresh" content="5; URL='/'" />
  <style>
  html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {
    font-size: 3.0rem;
    color: %color%;
    }
  </style>
</head>
</body>
<h2> I worked - device will reboot </h2>
</script>
</body>
</html>

)rawliteral";


const char test_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
<title>%title% Update Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {
    font-family: Arial; 
    display: inline-block; 
    text-align: center;
    }
    
    body {
     background-color: white;
     color: black;
    }
    
   .dark-mode {
    background-color: black;
    color: white;
   }
    
    h2 {
    font-size: 3.0rem;
    color: %color%;
    }
   .menu-buttons{
     margin-top: 1.0rem;
     margin-bottom: 1.0rem;
    }    
   .button {
     border: .15rem solid;
     border-radius: .4rem;
     font-weight: bold;
     padding: .25rem .6rem;
     text-align: center;
     text-decoration: none;
     display: inline-block;
     font-size: 1.0rem;
     margin: .5rem .5rem .5rem .5rem;
     cursor: pointer;
    }
   .button2 {
   background-color: %color%;
   color: White;
   border-color: %hover%;
   } 
   .button1:hover {
  background-color: %hover%;
  color: white;
  }

  .menu-reboot{
    border: 0.25rem solid %color%;
    border-radius: .4rem;
    width: 30rem;
    margin: auto;
    padding:  .4rem;
    } 
  
   .button3:hover {
  background-color: %hover%;
  color: white;
  }
  
   .label2{
    font-weight: bold;
    line-height: 1.2rem;
    min-height: 1.4rem;
    padding: .1rem .4rem .1rem 1.2rem;
    position: center;
    font-size: 1.25rem;
   }
  .pt-2 {padding-top: .75rem;}
  .form-input {
    margin-bottom: 1rem;
    background-image: none;
    border: 0.25rem dashed %hover%;
    border-radius: .4rem;
    font-weight: bold;
    color: %color%;
    font-size: 1rem;
    padding:  .4rem;
   }
     
    input[type="submit"] {
     background-color: %color%;
     color: white;
     font-size: 1.0rem;
     font-weight: bold;
     border:  .25rem solid %color%;
     border-radius: .4rem;
     font-weight: bold;
     padding:  .3rem .8rem;
     text-align: center;
     text-decoration: none;
     display: inline-block;
     margin: .9rem .45rem .4rem .4rem;
     cursor: pointer;
     }
    input[type="submit"]:hover {
     background-color: #ffffff;
     border-color: #000000;
     color: %color%;
     border: .25rem solid;
     border-radius: .4rem;
     font-weight: bold;
     font-size: 1.0rem;
     cursor: pointer;
     }

     .col-3{
    border: 0.25rem solid %color%;
    border-radius: .4rem;
    width: 30rem;
    margin: auto;
    padding:  .4rem;
   }
   
   .col-4{
    border: 0.25rem solid %color%;
    border-radius: .4rem;
    width: 30rem;
    margin-top: 2rem;
    margin: auto;
    padding:  .4rem;
   }

  .w3-background{
  background-color: %hover%;
  border-radius: .4rem;
  }
  
  .w3-progress{
  color: #ffffff;
  background-color: %color%;
  border-radius: .4rem;
  text-align:center;
  padding: .6rem .6rem .6rem .6rem;
  }

  .upload-bar{
   background-image: none;
   border: 0.25rem dashed %hover%;
   border-radius: .4rem;
   padding: 0.3rem 0.6rem 0.3rem 0.6rem;
   margin: auto;
   width: 26rem;
   }

   .mt-4 {
    margin-top: 5.0rem;
   }
   .label.label-primary {
    background: %color%;
    color: #fff;
    margin-left: .5rem;
    margin-right: .5rem;
    font-size: 1.0rem;
   }
   .label.label-rounded {
    border-radius: 5rem;
    padding-left: .5rem;
    padding-right: .5rem;
    font-size: 1.0rem;
   }
   
  </style>
  
</head>
<body>
   <h2>%title% Update Server</h2>
   
   <div class = "menu-buttons">
    <div class = "button button1">
      <button1 onclick="location.href='/home'">Home</button1>
    </div>
    <div class = "button button2">
      <button2>Management</button2>
    </div>
    <div class = "button button1">
    <button1 onclick="darkFunction()">Toggle dark mode</button1>
    </div>
   </div>
   
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
     
     <div class = "menu-buttons">
      <div class = "menu-reboot">
       <div class = "button button3">
        <button3 onclick="location.href='/reboot'">%processorplaceholder% Reboot</button3>
       </div>
      </div>
     </div>
     
    <div class="columns mt-4">
      <div class="col-12 text-center">
       <span class="label label-rounded mr-2">%IDplaceholder%</span> 
       -
       <span class="label label-rounded label-primary ml-2">%processorplaceholder%</span>
       -
       <span class="label label-rounded mr-2">%typeplaceholder%</span>
     </div>
    </div> 
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
      }
    };

    xhr.send(formData);
   }
});


function darkFunction() {
   var element = document.body;
   element.classList.toggle("dark-mode");
}


</script>
</body>
</html>

)rawliteral";

#endif
