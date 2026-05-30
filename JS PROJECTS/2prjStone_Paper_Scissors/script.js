let userchoice = document.querySelectorAll(".user .imagecon");
let compchoice = document.querySelectorAll(".comp .imagecon");
let msg = document.querySelector("#msg");
let userscore = document.querySelector("#userscore");
let compscore = document.querySelector("#compscore");
let msgbox = document.querySelector(".msgcon");
let urs= 0;
let comps = 0;
userchoice.forEach((ele)=>{
    ele.addEventListener("click",()=>{
     let MYchoice = ele.getAttribute("id");
     let COMPchoice= getcompchoice();

     compchoice.forEach((e)=>{
            e.querySelector("img").classList.remove("activechoice");
        });

        let compElement = document.getElementById(COMPchoice + "comp").querySelector("img");;
        compElement.classList.add("activechoice");
     playgame(MYchoice,COMPchoice);
    })
})
let option = ["rock", "paper", "scissorsr"];
 function getcompchoice(){
    let idx = Math.floor(Math.random()*3);
    return option[idx];
};
function playgame(MYchoice,COMPchoice){
    if( MYchoice===COMPchoice){
         msg.innerText = "It's a Draw 🤝";
    }
   else if (
        (MYchoice === "rock" && COMPchoice === "scissors") ||
        ( MYchoice=== "paper" &&  COMPchoice=== "rock") ||
        (MYchoice === "scissors" && COMPchoice === "paper")
    ){
        urs++;
        userscore.innerText=urs;
                msg.innerText = `you win-> ${MYchoice} beats ${COMPchoice}`;
        msgbox.style.backgroundColor = "green";
    }else{
           comps++;
           compscore.innerText=comps;
           msg.innerText = `you lose-> ${COMPchoice} beats ${MYchoice}`;
           msgbox.style.backgroundColor = "red";
    }
}
