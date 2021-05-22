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
    
     .name-host {
    font-size: 1.0rem;
    margin-bottom: .4rem;
    }
    .name-text {
    font-size: 1.2rem;
    font-weight: bold;
    }
    .name-mac {
    font-size: 1.0rem;
    margin-bottom: 10.0rem;
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
   .button1 {
   background-color: %color%;
   color: white;
   border-color: %hover%;
   }
  
  .button2:hover {
  background-color: %hover%;
  color: white;
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
   <h2>%title% Home</h2>
   
  
   <div class = "menu-buttons">
   <div class = "button button1">
     <button1>Home</button>
    </div>
    <div class = "button button2">
     <button2 onclick="location.href='/update'">Management</button>
    </div>
    <div class = "button button2">
    <button2 onclick="darkFunction()">Toggle dark mode</button2>
    </div>
   </div>
   
    <div class = "name-host">
    <span class = "name-text">IP Address:</name-text></span>
    <span class = "host">%ipplaceholder%</host></span>
   </div>
   
   <div class = "name-mac">
    <span class = "name-text">MAC Address:</name-text></span>
    <span class = "host">%macplaceholder%</host></span>
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
  </div>
  
   <script>
  function darkFunction() {
   var element = document.body;
   element.classList.toggle("dark-mode");
}
 


</script>
</body>
</html>

)rawliteral";

#endif
