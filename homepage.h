/* Webpage HTML - this is the homepage*/ 

#ifndef homepage_h
#define homepage_h


const char home_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
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
    
    .name-host {
    font-size: 16px;
    margin-bottom: 5px;
    }
    .name-text {
    font-size: 20px;
    font-weight: bold;
    }
    .name-mac {
    font-size: 16px;
    margin-bottom: 60px;
    }
    
   .menu-buttons{
     margin-bottom: 30px;
    }
    
    .name-adendem {
    font-size: 10px;
    margin-bottom: 5px;
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
    margin-top: 10px;
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
   
    <div class = "name-host">
    <span class = "name-text">*Host Name:</name-text></span>
    <span class = "host">%hostplaceholder%</host></span>
   </div>
   
   <div class = "name-mac">
    <span class = "name-text">MAC Address:</name-text></span>
    <span class = "host">%macplaceholder%</host></span>
   </div>
   
   <div class = "name-adendem">
    <span class = "name-text1">
    *host name may or may not be correct based on your local Network Settings
    </name-text1></span>
   </div>
   
    <div class="columns mt-4">
      <div class="col-12 text-center">
       <span class="label label-rounded mr-2">%IDplaceholder%</span> 
       -
       <span class="label label-rounded label-primary ml-2">%processorplaceholder%</span>
     </div>
    </div> 
  </div>
  
 


</script>
</body>
</html>

)rawliteral";

#endif
