package com.bignerdranch.android.psychologicalassistant

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.text.TextUtils
import android.widget.Button
import android.widget.TextView
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val helpButton=findViewById<Button>(R.id.psy_button)
        val helpText=findViewById<TextView>(R.id.psy_text)
        var arrayOfHelp=listOf("Ты всегда знаешь как меня удивить!","" +
                "Я вижу столько тепла в твоих глазах",
        "Твой смех очаровывает!",
        "Я очень сильно ценю тебя!",
        "Мне так нравится твой стиль!")
        helpButton.setOnClickListener{
            if(TextUtils.isEmpty(helpText.text)){
                    var textNumber=(0..arrayOfHelp.size).random()
                    helpText.text=arrayOfHelp[textNumber]
            } else {
                Toast.makeText(this,"Хорошо, что помощь оказалась ненужна.",Toast.LENGTH_LONG).show()
            }
        }
    }
}