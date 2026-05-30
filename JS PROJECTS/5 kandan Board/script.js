let todo = document.querySelector("#todo");
let progress= document.querySelector("#progress");
let done = document.querySelector("#done");
let taskboxes=document.querySelectorAll(".taskbox");
let addnewtaskNavbar=document.querySelector("#navbar_addTask_btn");
let modal_add_task_btn = document.querySelector("#addnewtask");
let modalNewtask= document.querySelector(".modal_newTask");
let overlay = document.querySelector(".overlay");
let modal_textinput= document.querySelector("#modal_textinput");
let modal_textarea= document.querySelector("#textarea");
let dragElement= null;

 /**TASK1 enters progress column
           Use for:
              add dashed border
              highlight column */
function addDragAndDrop(col){
    col.addEventListener("dragenter",(ele)=>{
         col.classList.add("drag-hover");
        
    })
    col.addEventListener("dragleave",(ele)=>{
          col.classList.remove("drag-hover");
    })
    col.addEventListener("dragover",(ele)=>{
        //Browser blocks dropping by default.
          ele.preventDefault();
    })
    col.addEventListener("drop",(ele)=>{
        col.appendChild(dragElement);
          col.classList.remove("drag-hover");
          addingData();
          updatecount();
          
    })
}
/**Example:
         User picks TASK1
           Use for:
         saving dragged element
        adding drag style */
taskboxes.forEach(task=> {
    task.addEventListener("dragstart",(ele)=>{
      dragElement= task;
       
    })
});
addDragAndDrop(todo);
addDragAndDrop(progress);
addDragAndDrop(done);
addnewtaskNavbar.addEventListener("click",()=>{
   modalNewtask.classList.add("active");
})
overlay.addEventListener("click",()=>{
  modalNewtask.classList.remove("active");
})
// logic of when we click addnew task btn do add task in todo 
// , make it dragable 
modal_add_task_btn.addEventListener("click",()=>{

    let textinput = modal_textinput.value;
    let textareainput = modal_textarea.value;

   

    todo.appendChild(createTask(textinput,textareainput));
 
     updatecount();
     addingData();
  
    modalNewtask.classList.remove("active");
   document.querySelector("#modal_textinput").value="";
   document.querySelector("#textarea").value="";

});
gettingData();
function updatecount(){
   
   [todo, progress, done].forEach(ele=>{
    let countno =ele.querySelector(".right");
    let countele=ele.querySelectorAll(".taskbox").length;
    countno.innerText = countele;
   })
}
//adding tasks data into taskdata obj
function addingData(){
    let taskdata ={};// making a task obj to store data in local storage 
    [todo, progress, done].forEach(ele=>{
        let taskboxes =
        ele.querySelectorAll(".taskbox");

        taskdata[ele.id]= Array.from(taskboxes).map(t=>{
            return{
                title: t.querySelector("h3").innerText,
                desc: t.querySelector("p").innerText
            }
        } )
    })
    //adding data to local storage
    localStorage.setItem("kanban data",JSON.stringify(taskdata));
}
function createTask(title, desc){

   let taskboxdiv =
   document.createElement("div");

   taskboxdiv.classList.add("taskbox");

   taskboxdiv.setAttribute(
      "draggable",
      "true"
   );

   taskboxdiv.innerHTML = `
    
        <div class="taskleft">
            <h3>${title}</h3>
            <p>${desc}</p>
        </div>

        <div class="taskright">
            <button class="btn_task">
                DEL
            </button>
        </div>
    `;

    taskboxdiv.addEventListener("dragstart",()=>{
      dragElement=taskboxdiv;
    })
    const delbtn = taskboxdiv.querySelector("button");
    delbtn.addEventListener("click",()=>{
        taskboxdiv.remove();
        updatecount();
        addingData();
    })
    return taskboxdiv;
}
function gettingData(){
    if(localStorage.getItem("kanban data")){
        let data =JSON.parse(localStorage.getItem("kanban data"));
        for( const ele in data){
            const taskincol = document.querySelector(`#${ele}`);
            data[ele].forEach(coldata=>{
               
                taskincol.appendChild(createTask(coldata.title,coldata.desc));
            })
        }
    }
}