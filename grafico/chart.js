window.onload = function () {
    g = new Dygraph(
            document.getElementById("graphdiv"),
            data,
            {
                labels: ["Tam entrada", "O (n)","O (log n)"],
                strokeWidth: 3,
                colors: ["rgb(51,204,204)","rgb(204,21,204)"],
            }
    );
}