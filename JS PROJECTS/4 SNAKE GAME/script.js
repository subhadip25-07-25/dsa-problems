
let board = document.querySelector(".board");
let blockheight = 30;
let blockwidth = 30;
let rows = Math.floor(board.clientHeight / blockheight);
let cols = Math.floor(board.clientWidth / blockwidth);
let direction = "down";
let intervalID = null;
const arr = [];// works as 2d array , cus in js we cant make 2d aary directly 
let snake = [{ r: 1, c: 3 }]
let stbtn= document.querySelector("#stbtn");
let btn = document.querySelector(".btn");
let popuphead = document.querySelector(".head");
let heading = document.querySelector(".heading");
let highscoreEle= document.querySelector(".highscore");
let scoreEle=document.querySelector(".score");
let timeEle= document.querySelector(".time");
let score = 0;
let highscore= Number(localStorage.getItem("highscore"))||0;
let time = "00-00";
let timeIntervalId= null;
let stGameModel = document.querySelector(".stgamemodel");
let resetGameModel = document.querySelector(".resetgamemodel");
let resetbtn= document.querySelector("#resetbtn");

highscoreEle.innerText=highscore;
let food = {
    fr: Math.floor(Math.random() * rows),
    fc: Math.floor(Math.random() * cols)
}
for (let i = 0; i < rows; i++) {
    arr[i] = [];// making row now its 2d arry 
    for (let j = 0; j < cols; j++) {
        let block = document.createElement("div");
        block.classList.add("cell");
        arr[i][j] = block;
        // arr[`${i},${j}`]=block;// 1d arrya format
        board.appendChild(block);

    }
}
const rendersanke = () => {
    snake.forEach(ele => {
        // arr[`${ele.r},${ele.c}`] .classList.add("fill");
        arr[ele.r][ele.c].classList.add("fill");

    })
    arr[food.fr][food.fc].classList.add("food");


}
 const startgame=()=>{
intervalID = setInterval(() => {
    let head = null;
    if (direction === "left") {
        head = { r: snake[0].r, c: snake[0].c - 1 };
    }
    else if (direction === "right") {
        head = { r: snake[0].r, c: snake[0].c + 1 };
    }
    else if (direction === "up") {
        head = { r: snake[0].r - 1, c: snake[0].c };
    }
    else if (direction === "down") {
        head = { r: snake[0].r + 1, c: snake[0].c };
    }
    snake.forEach(ele => {
        // arr[`${ele.r},${ele.c}`] .classList.add("fill");
        arr[ele.r][ele.c].classList.remove("fill");
    })
    snake.unshift(head);
    snake.pop();
    // stopping consition 
    if (head.r < 0 || head.c < 0 || head.r >= rows || head.c >= cols) {
        clearInterval(intervalID);
        intervalID = null;
        stGameModel.style.display="none";
        resetGameModel.style.display="flex";
       board.style.filter= "blur(3px)";
      clearInterval(timeIntervalId);
    timeIntervalId = null;

       // setting high score 
      // HighScorefind();
      if(score>=highscore){
        highscore=score;
        localStorage.setItem("highscore",highscore.toString());
        // local store stroe nad read only string format 
     }
       return;
    }
    // eating food ,inc length
    if (head.r == food.fr && head.c == food.fc) {
        arr[food.fr][food.fc].classList.remove("food");
        food = {
            fr: Math.floor(Math.random() * rows),
            fc: Math.floor(Math.random() * cols)
        }
        arr[food.fr][food.fc].classList.add("food");
        snake.unshift(head);
        score+=10;
        scoreEle.innerText=score;
    }
    rendersanke();
}, 200)
 }
/*
ArrowUp
ArrowLeft
ArrowDown*/
addEventListener("keydown", (evt) => {
    evt.preventDefault();
    if (evt.key === "ArrowUp") {
        direction = "up";
    }
    else if (evt.key === "ArrowDown") {
        direction = "down";
    }
    else if (evt.key === "ArrowLeft") {
        direction = "left";
    }
    else if (evt.key === "ArrowRight") {
        direction = "right";
    }
})
// stbtn work 
stbtn.addEventListener("click", ()=>{
      score= 0;
      time="00-00";
      stGameModel.style.display="none";
       resetGameModel.style.display="none";
      board.style.filter= "blur(0px)";
      timer();
      startgame();

})
resetbtn.addEventListener("click",()=>{
    snake = [{ r:1, c:3 }];
    direction = "down";
    score=0;
    time="00-00";
     board.style.filter= "blur(0px)";
    resetGameModel.style.display="none";
highscoreEle.innerText=highscore;
    scoreEle.innerText=score;
    startgame();
})
const timer=()=>{
    timeIntervalId=setInterval(()=>{
        let[min,sec]=time.split("-").map(Number);
        if(sec==59){
            min=min+1;
            sec= 0;
        }else{
            sec++;
        }
        time=`${min}-${sec}`;
        // what if we chnag timer 00:00 
        timeEle.innerText=time;
    },1000)
}