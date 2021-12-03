fun main(args:Array<String>){
    println("У меня есть пару вопросов к тебе. Если не сложно, отвечай на них y и n.")
    println("Вам нужна психологическая поддержка?")
    question()
}

fun question() {
    var anser = readLine()
    if(anser=="y") Psi()
    else Exit()
}
fun Psi(){
    var compliment = arrayOf("Ты огромный молодец!", "Ты так стараешься! Это застуживает восхищения!", "Мне нравится твой стиль!","У тебя точно всё получится!")
    println(compliment[(Math.random()*compliment.size).toInt()])
    println("Ещё поддержки?")
    question()
}
fun Exit(){
    println("Вы хотите выйти?")
    var anser= readLine();
    if(anser=="y") println("Удачи! Пока!")
    else {
        println("Значит всё же нужна?")
        question()
    }
}