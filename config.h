/* WIFI */
const char* ssid = "........";
const char* password = "........";

const char* host     = "ESP-OTA";






/* Webpage HTML */ 

#ifndef Webpage_h
#define Webpage_h


const char home_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
<title>ESP Web Home</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {
    font-size: 3.0rem;
    color: #5900b8;
    }
   .menu-buttons{
     margin-bottom: 40px;
    }
    
   .button {
     border: 2px solid;
     border-radius: .4rem;
     border-color: black;
     font-weight: bold;
     padding: 4px 8px;
     text-align: center;
     text-decoration: none;
     display: inline-block;
     font-size: 16px;
     margin: 4px 4px 4px 4px;
     cursor: pointer;
    }
   .button1 {
   background-color: #5900b8;
   color: white;
   } 
   .button2 {
   background-color: #ffffff;
   color: black;
   }
  .button2:hover {
  background-color: #b370fa;
  color: white;
  }

   .mt-4 {
    margin-top: 40px;
   }
   .label {
    font-size: 16px;
   }
   .label.label-primary {
    background: #5900b8;
    color: #fff;
    margin-left: 5px;
   }
   .label.label-rounded {
    border-radius: 5rem;
    padding-left: .5rem;
    padding-right: .5rem;
   }
   
  </style>
  
</head>
<body>
   <h2>ESP Web Home</h2>
   
   <div class = "menu-buttons">
   <div class = "button button1">
     <button1>Home</button>
    </div>
    <div class = "button button2">
     <button2 onclick="location.href='/update'">Update</button>
    </div>
   </div>
   
    <div class="columns mt-4">
      <div class="col-12 text-center">
       <span class="label label-rounded mr-2">*******</span> 
       -
       <span class="label label-rounded label-primary ml-2">ESP8266</span>
     </div>
    </div> 
  </div>
  
 


</script>
</body>
</html>

)rawliteral";


const char update_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
<title>ESP Web Update Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {
    font-size: 3.0rem;
    color: #5900b8;
    }
   .menu-buttons{
     margin-bottom: 40px;
    }
    
   .button {
     border: 2px solid;
     border-radius: .4rem;
     border-color: black;
     font-weight: bold;
     padding: 4px 8px;
     text-align: center;
     text-decoration: none;
     display: inline-block;
     font-size: 16px;
     margin: 4px 4px 4px 4px;
     cursor: pointer;
    }
   .button1 {
   background-color: #ffffff;
   color: BLACK;
   } 
   .button2 {
   background-color: #5900b8;
   color: White;
   } 
   .button1:hover {
  background-color: #b370fa;
  color: white;
  }
  

   .label2{
    font-weight: bold;
    line-height: 1.2rem;
    min-height: 1.4rem;
    padding: .1rem .4rem .1rem 1.2rem;
    position: center;
    font-size: 24px;
   }
  .pt-2 {padding-top: 12px;}
  .form-input {
    background: #fff;
    background-image: none;
    border: 0.20rem dashed #5900b8;
    border-radius: .4rem;
    color: #3b4351;
    font-size: 14px;
    padding: 4px;
   }
   .mt-4 {
    margin-top: 40px;
   }
   .label {
    font-size: 16px;
   }
   .label.label-primary {
    background: #5900b8;
    color: #fff;
    margin-left: 5px;
   }
   .label.label-rounded {
    border-radius: 5rem;
    padding-left: .5rem;
    padding-right: .5rem;
   }
   
  </style>
  
</head>
<body>
   <h2>ESP Web Update Server</h2>
   
   <div class = "menu-buttons">
    <div class = "button button1">
      <button1 onclick="location.href='/home'">Home</button>
    </div>
    <div class = "button button2">
      <button2>Update</button>
    </div>
   </div>
   
   <div class="col-12 mt-3 p-centered">
  
     <div class="col-3 col-sm-9 col-md-6 p-centered">
       <label class="label label2 mr-2">Upload Firmware Here</label>
     <div class="form-group pt-2 mt-3"><input type="file" accept=".bin" class="form-input file-input">
     </div>
    <div class="columns mt-4">
      <div class="col-12 text-center">
       <span class="label label-rounded mr-2">*******</span> 
       -
       <span class="label label-rounded label-primary ml-2">ESP8266</span>
     </div>
    </div> 
  </div>
  
 


</script>
</body>
</html>

)rawliteral";



#endif
