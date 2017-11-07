window.onload = function () {
    g = new Dygraph(
            document.getElementById("graphdiv"),
            "data.csv",
            {
                labels: ["tempo", "Melhor solucao"],
                strokeWidth: 3,
                colors: ["rgb(51,204,204)"],
            }
    );
}