/**
* this function validate the fields from form of file index.html
*/
function validateFields(){
  var inputName = document.getElementById("inputName").value;
  var inputTel = document.getElementById("inputTel").value;
  if(inputName === "" || inputTel === ""){
    alert("Há campos a serem preenchidos!");
    if(inputName === ""){
      document.getElementById("inputName").focus();
    }else if(inputTel === ""){
      document.getElementById("inputTel").focus();
    }
  }else{
    alert("Cadastro feito com sucesso!");
  }
}
