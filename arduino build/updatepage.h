/* Webpage HTML - this is the update page */ 

#ifndef updatepage_h
#define updatepage_h

const char update_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
<title>%title% Update Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {
    font-size: 3.0rem;
    color: %color%;
    }
   .menu-buttons{
     margin-bottom: 1.0rem;
    }    
   .button {
     border: .15rem solid;
     border-radius: .4rem;
     border-color: black;
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
   background-color: #ffffff;
   color: BLACK;
   } 
   .button2 {
   background-color: %color%;
   color: White;
   } 
   .button1:hover {
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
    background: #fff;
    background-image: none;
    border: 0.20rem dashed %color%;
    border-radius: .4rem;
    color: %hover%;
    font-size: .9rem;
    padding:  .4rem;
   }
     
    input[type="submit"] {
     background-color: #000000;
     border-color: #000000;
     color: white;
     font-size: 1.0rem;
     font-weight: bold;
     border:  .25rem solid;
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
     border-color: #ffffff;
     color: %color%;
     border: .25rem solid;
     border-radius: .4rem;
     font-weight: bold;
     font-size: 1.0rem;
     cursor: pointer;
     
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
      <button2>Update</button2>
    </div>
   </div>
   
   <div class="col-12 mt-3 p-centered">
  
     <div class="col-3 col-sm-9 col-md-6 p-centered">
       <label class="label label2 mr-2">Upload Firmware Here</label>
    <div class="form-group pt-2 mt-3">
    <form method="POST" action="/doUpdate" enctype="multipart/form-data" id="upload_form">
    <input type="file" name="/update" id="file" accept=".bin" class="form-input file-input">
    <input type="submit" value="FLASH">
    </form>
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
 

</script>
</body>
</html>


)rawliteral";



#endif
