/* Webpage HTML - this is the config page*/ 

#ifndef config_page_h
#define config_page_h

const char config_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head>
    <title>%title% Config</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <meta http-equiv="expires" content="0">

    
    
    <style>
     %dark%
    
<style>
   
body {
   margin:0;
   padding:0;
}
#container {
   position:relative;
   min-height: 100%%;
}
#header {
   padding:00px;
}
#body {
   padding:100px;
}
#footer {
   height:100px;   /* Height of the footer */
   position:absolute;
   bottom:0;
   width:100%%;
}

   html {font-family: Arial; display: inline-block; text-align: center;}
   h2 {
    font-size: 3.0rem;
    color: %color%;
    margin-bottom: 0.4rem;
   }
   .menu-buttons{
     margin-top: 1.0rem;
     margin-bottom: 1.0rem;
   }
   .menu-reboot{
    border: 0.25rem solid #005500;
    border-radius: .4rem;
    width: 30rem;
    margin: auto;
    padding:  .4rem;
   }     
   .button {
     border: .15rem solid;
     border-radius: .4rem;
     font-weight: bold;
     padding: .25rem .6rem;;
     text-align: center;
     text-decoration: none;
     display: inline-block;
     font-size: 1.0rem;
     margin: .5rem .5rem .5rem .5rem;;
     cursor: pointer;
   }
   .ButtonHere {
    background-color: %color%;
    border-color: %hover%;
    color: White;
   } 
   .ButtonClickable:hover {
    background-color: %hover%;
    color: white;
   }

    .name-status {
     border-radius: .4rem;
     font-weight: bold;
     padding: .25rem .6rem;
     display: inline-block;
     margin-bottom: 1rem;
    }

    .name-text {
    font-size: 1.2rem;
    font-weight: bold;
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
    margin-top: 0.15rem;
   }
   .label {
    font-size: 1.0rem;;
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

    .mt-8 {
    margin-top: 5px;
    }
   
   .label.label-error {
    background: %color%;
    color: #fff;
    padding-left: 10rem;
    padding-right: 10rem;
   }
   
   .mt-10 {
    margin-top: 5px;
    }
    
   .label.label-blank {
    background: %color%;
    color: #fff;
    padding-left: 10rem;
    padding-right: 10rem;
   }

  </style>


  </head>
  <body>
  
    <div id="container">

      <div id="header">
        <h2>%title% - <em>config</em></h2>
        <div class = "menu-buttons">
          <div class = "button ButtonClickable">
            <Button1 onclick="location.href='/home'">Home</button>
          </div>
          <div class = "button ButtonHere">
            <Button2>config</button2>
          </div>
          <div class = "button ButtonClickable">
           <button3 onclick="darkFunction()">Dark Mode</button3>
          </div>
        </div>
      </div>  <!-- HEADER -->

       <div id="body"> 

      <div class = "name-status" id="state" style="background:green">
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

    <script>
      function darkFunction() {
       var xhr = new XMLHttpRequest();
       xhr.open("GET", "/darkmode?state=1", true);
       xhr.send();
       setTimeout(function () {window.location.href = "/home";}, 100);
      }

      function checkConnectionStatus()
{
    let xhttp = new XMLHttpRequest();
    xhttp.timeout = 2000;
    xhttp.onreadystatechange = function()
    {
        if (this.readyState == 4)
        {
            if (this.status == 200)
            {
                document.getElementById("state").style.background = "green";
            }
            else
            {
                document.getElementById("state").style.background = "red";
            }
             setTimeout(checkConnectionStatus, 5000);
            // Repeat our status check only once there's a result
        }
    }
    xhttp.open("GET", "/state", true);
    xhttp.send();
}
// Initial status check
setTimeout(checkConnectionStatus, 5000);

   </script>
  </body>
</html>
)rawliteral";

#endif //
