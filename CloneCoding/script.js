const h1 = document.querySelector("div.Hello:first-child h1")
console.log(h1)
console.dir(h1)

function handleTitleClick(){
    console.log("title was clicked.");
    h1.style.color = "blue"
}

function handleMounsEnter(){
    h1.innerText = "Mouse is here!";
}

function handleMounsLeave(){
    h1.innerText = "Mouse is gone!";
}

function handleWindowResize(){
    document.body.style.backgroundColor = "tomato";
}

function handleWindowCopy(){
    alert("copier!");
}

function handleWindowOffline(){
    alert("SOS no WIFI");
}

function handleWindowOnline(){
    alert("ALL GOOD");
}

//if user click, excute hadleTitle Click
// title.addEventListener("click", handleTitleClick);
// title.addEventListener("mouseenter", handleMounsEnter);

h1.onclick = handleTitleClick;
h1.onmouseenter = handleMounsEnter;
h1.addEventListener("mouseleave", handleMounsLeave);

window.addEventListener("resize", handleWindowResize);
window.addEventListener("copy", handleWindowCopy);
window.addEventListener("offline", handleWindowOffline);
window.addEventListener("online", handleWindowOnline);