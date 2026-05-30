let btn = document.querySelectorAll('.box');
let msgbox = document.querySelector('.msgcon');
let winmsg = document.querySelector('.msg');
let newbtn = document.querySelector('.newbtn');
let resetbtn = document.querySelector('.reset');
let turno= true;
const winning=[
    [0,1,2],[0,3,6],[0,4,8],[3,4,5],[6,7,8],[1,4,7],[2,5,8],[2,4,6]
];
btn.forEach((ele, index)=>{
    ele.addEventListener("click",()=>{
       if( turno){
        ele.innerText ='O';
        ele.style.color="blue"
        turno= false;
       }
       else{
        ele.innerText = 'X';
        ele.style.color="red";
        turno= true;
       }
       ele.disabled= true;
     let winner = checkwinner();
      if(winner){
        showwinner(winner);
        disablebox();
      }
    })
})
const checkwinner = () => {
    for (let pattern of winning) {

        let pos1 = btn[pattern[0]].innerText;
        let pos2 = btn[pattern[1]].innerText;
        let pos3 = btn[pattern[2]].innerText;

        if (pos1 !== "" && pos2 !== "" && pos3 !== "") {
            if (pos1 === pos2 && pos2 === pos3) {
                return pos1;  // 🔥 returns "X" or "O"
            }
        }
    }
};
const showwinner=(winner)=>{
   
    winmsg.innerText= `winner is ${winner}`;
    msgbox.classList.remove("hide");
}

const disablebox=()=>{
btn.forEach((ele)=>{
    ele.disabled=true;
})
}
const enablebox=()=>{
    btn.forEach((ele)=>{
        ele.disabled= false;
        ele.innerText="";
    })
}
const newgame=()=>{
    // we have to do all button clickable , turn again reset it applicabele for bith reset and new buttuon 
    turno= true;
    enablebox();
    msgbox.classList.add("hide");
}
newbtn.addEventListener("click",newgame);
resetbtn.addEventListener("click",newgame);