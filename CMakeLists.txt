cmake_minimum_required(VERSION 3.26)
project(sonartson C)

set(CMAKE_C_STANDARD 11)

add_executable(quiz_programi main.c
        quiz.h
        soruSor.c
        cevapKontrol.c
        quizBaslat.c
        cevapKontrol.c)
