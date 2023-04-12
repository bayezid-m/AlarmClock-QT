#include "myapp.h"
#include <QtCore>
#include <QDebug>
#include <QDateTime>
#include <QtMultimedia/QMediaPlayer>

QMediaPlayer* mediaPlayer = new QMediaPlayer;

int hour = 0;
int minute = 0;
int day = 0;
int month = 0;
int second = 0;
int init = 0;
int flash = 0;
int change = 0;
int convert = 0;
int apc = 1;
int ampm = 1;
int alarm = 0;
int alarmH1 = 0;
int alarmM1 = 0;
int alarmH2 = 0;
int alarmM2 = 0;
int alnum = 1;
int alset = 1;
int offnum = 1;
int snooze = 0;

bool starter = false;
bool starter2 = false;
bool format = false;
bool pm = false;
bool activator = false;
bool amp = false;
bool alm1 = false;
bool alm2 = false;
bool alsound1 = false;
bool alsound2 = false;

QString hourFix;
QString minuteFix;
QString amp2 = "PM";
QString offMessage = "OFF";
QString offMessage2 = "OFF";
QString mainal1 = "Al1";
QString mainal2 = "Al2";

myapp::myapp()
{
    mediaPlayer->setMedia(QUrl::fromLocalFile("E:/radioicon/Alarm.mp3"));
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    hour = time.hour();
    minute = time.minute();
    day = date.day();

    month = date.month();
    alarmH1 = hour;
    alarmM1 = minute;
    alarmH2 = hour;
    alarmM2 = minute;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
    timer->start(400);

}
void myapp::MySlot(){
       init++;
       second++;
       qDebug()<< second;
//       alarmH1 = hour;
//       alarmM1 = minute;
       if(minute < 10){
            minuteFix = "0" + (QString::number(minute));
            emit sendMess2(QString(minuteFix));
       }
       if(hour < 10){
            hourFix = "0" + (QString::number(hour));
            emit sendMess(QString(hourFix));
       }
       if(second == 1){
            emit sendMess2(QString::number(minute));
            emit sendMess(QString::number(hour));
            emit sendMess7(QString::number(day));
            emit sendMess8(QString::number(month));
       }
       if(pm == true){
           emit sendMess3(QString(amp2));
       }

       if(second == 60){
           minute += 1;
           second = 0;
           emit sendMess2(QString::number(minute));
       }
       if(minute == 60){
           hour += 1;
           minute = 0;
           emit sendMess(QString::number(hour));
       }
           if(change == 0){
                if(init%2==0){
                  emit sendMess4(QString(""));
              }
              else{
                  emit sendMess4(QString(":"));
              }
            }
           if(pm == true){
               if(hour == 0){
                   hour = 12;
               }
           }
           else if(pm == false){
               if(hour == 24){
                   hour = 0;
               }
           }

           if(starter == true){
              emit sendMess4(QString(":"));
              if(change == 1){
                 if(init%2==0){
                   emit sendMess(QString(""));
               }
               else{
                   emit sendMess(QString::number(hour));
               }
           }
            else if(change == 2){
                     if(init%2==0){
                       emit sendMess2(QString(""));
                   }
                   else{
                       emit sendMess2(QString::number(minute));
                   }
              }
            else if(change == 3){
                  if(format == false){
                       emit sendMess(QString::number(24));
                       emit sendMess2(QString("hr"));
                  }
                  else if(format == true){
                       emit sendMess(QString::number(12));
                       emit sendMess2(QString("hr"));
                  }
              }
             else if(change == 4 && pm == true){
                  if(init%2==0){
                    emit sendMess3(QString(""));
                }
                else{
                    emit sendMess3(QString(amp2));
                }
             }
             else if(change == 0){
                  if(init%2==0){
                    emit sendMess4(QString(""));
                }
                else{
                    emit sendMess4(QString(":"));
                }
              }
              else if(pm == false){
                  emit sendMess3(QString(" "));
              }
       }
           if(starter2 == true){
               emit sendMess(QString("AL"));
               emit sendMess4(QString(":"));
               emit sendMess2(QString::number(alset));
               if(alset == 1){
                   if(alarm == 2){
                      emit sendMess2(QString::number(alarmM1));
                      if(init%2==0){
                        emit sendMess(QString(""));
                    }
                    else{
                        emit sendMess(QString::number(alarmH1));
                    }
                  }
                   else if (alarm == 3){
                       emit sendMess(QString::number(alarmH1));
                       if(init%2==0){
                         emit sendMess2(QString(""));
                     }
                     else{
                         emit sendMess2(QString::number(alarmM1));
                     }
                   }
                   else if(alarm == 4){
                         emit sendMess(QString(""));
                         emit sendMess4(QString(""));
                         emit sendMess2(QString(offMessage));
                   }
                   else if(alarm == 5){
                          starter2 = false;
                          alarm = 0;
                          change = 0;
                          emit sendMess(QString::number(hour));
                          emit sendMess2(QString::number(minute));
                          if(offMessage == "ON"){
                              alm1 = true;
                             // emit sendMess5(QString(mainal1));
                          }
                   }
               }
               else if(alset == 2){
                   if(alarm == 2){
                      emit sendMess2(QString::number(alarmM2));
                      if(init%2==0){
                        emit sendMess(QString(""));
                    }
                    else{
                        emit sendMess(QString::number(alarmH2));
                    }
                  }
                   else if (alarm == 3){
                       emit sendMess(QString::number(alarmH2));
                       if(init%2==0){
                         emit sendMess2(QString(""));
                     }
                     else{
                         emit sendMess2(QString::number(alarmM2));
                     }
                   }
                   else if(alarm == 4){
                         emit sendMess(QString(""));
                         emit sendMess4(QString(""));
                         emit sendMess2(QString(offMessage2));
                   }
                   else if(alarm == 5){
                          starter2 = false;
                          alarm = 0;
                          change = 0;
                          emit sendMess(QString::number(hour));
                          emit sendMess2(QString::number(minute));
                          if(offMessage2 == "ON"){
                              alm2 = true;
                             // emit sendMess5(QString(mainal1));
                          }
                   }
               }

           }

           if(alm1 == true){
               emit sendMess5(QString(mainal1));
           }
           if(alm2 == true){
               emit sendMess6(QString(mainal2));
           }
           if(init == 20){
               starter = false;
               starter2 = false;
                emit sendMess(QString::number(hour));
                emit sendMess2(QString::number(minute));
                change = 0;
           }

           if(alarmH1 == hour && alarmM1 == minute && alm1 == true){
               mediaPlayer->play();
               if(init%2==0){
                 emit sendMess5(QString(""));
             }
             else{
                 emit sendMess5(QString(mainal1));
             }
           }
           if(alarmH2 == hour && alarmM2 == minute && alm2 == true){
               mediaPlayer->play();
               if(init%2==0){
                 emit sendMess6(QString(""));
             }
             else{
                 emit sendMess6(QString(mainal2));
             }
       }
}

void myapp::func_btn_set(){
   change += 1;
       if(change == 4){
           if(format == true){
              pm = true;
              if(hour > 12){
                  hour = hour - 12;
                  emit sendMess3(QString("PM"));
              }
              //change = 0;
           }
           else if(format == false){
               pm = false;
               emit sendMess3(QString(""));
               if(hour <= 12 && activator == true && amp2 == "PM"){
                   hour = hour + 12;
               }

           }
        }
        if(change == 5){
            change = 0;
            starter = false;
        }
   starter = true;
   init = 0;
   second = 0;
   emit sendMess(QString::number(hour));

     alarmH1 = hour;
     alarmM1 = minute;
     alarmH2 = hour;
     alarmM2 = minute;

}
void myapp::func_btn_al(){
    alarm += 1;
    change = 1;
    starter2 = true;


}
void myapp::func_btn_unset(){

}

void myapp::func_btn_stop(){
    if(alarmH1 == hour && alarmM1 == minute && alm1 == true){
        alarmM1 = alarmM1 + 1;
    }
    if(alarmH2 == hour && alarmM2 == minute && alm2 == true){
        alarmM2 = alarmM2 + 1;
    }

    snooze++;
    mediaPlayer->stop();
    if(alm1 == true){
        if(snooze == 3){
            alm1 = false;
            emit sendMess5(QString(""));
            offMessage = "OFF";
            mediaPlayer->stop();
            snooze = 0;
        }
    }
    if(alm2 == true){
        if(snooze == 3){
            alm2 = false;
            emit sendMess5(QString(""));
            offMessage2 = "OFF";
            mediaPlayer->stop();
            snooze = 0;
        }
    }



}
void myapp::func_btn_up(){
   init = 0;
   second = 0;
       if(alarmH1 == hour && alarmM1 == minute && alm1 == true){
           alm1 = false;
           emit sendMess5(QString(""));
           offMessage = "OFF";
           mediaPlayer->stop();
       }
       if(alarmH2 == hour && alarmM2 == minute && alm2 == true){
           alm2 = false;
           emit sendMess6(QString(""));
           offMessage2 = "OFF";
           mediaPlayer->stop();
       }
       ////////////////////////////////
       if(starter == true){
           if(change == 1){
                hour += 1;
           }
           else if(change == 2){
               minute += 1;
           }
           else if(change == 3){
               apc++;
               if(apc%2==0){
                   format = true;
                   activator = true;
               }
               else {
                   format = false;
                   //activator = false;
               }

           }
           else if(change == 4 && pm == true){
               ampm++;
               if(ampm%2==0){
                  amp2 = "AM";
               }
               else{
                   amp2 = "PM";
               }
           }
       }

       if(starter2 == true){
           if(alarm == 1){
               alnum++;
               if(alnum%2==0){
                  alset = 2;
               }
               else{
                   alset = 1;
               }
           }
           if(alset == 1){
               if(alarm == 2){
                  if(pm == true){
                     alarmH1 += 1;
                     if(alarmH1 == 13){
                         alarmH1 = 1;
                     }
                  }
                  else if(pm == false){
                      alarmH1 += 1;
                      if(alarmH1 == 24){
                          alarmH1 = 0;
                      }
                  }
              }
              if(alarm == 3){
                  alarmM1 += 1;
                  if(alarmM1 == 61){
                      alarmM1 = 1;
                  }

              }
              if(alarm == 4){
                offnum++;
                if(offnum%2==0){
                   offMessage = "ON";
                }
                else{
                    offMessage = "OFF";
                }
              }

           }
           else if(alset == 2){
               if(alarm == 2){
                  if(pm == true){
                     alarmH2 += 1;
                     if(alarmH2 == 13){
                         alarmH1 = 1;
                     }
                  }
                  else if(pm == false){
                      alarmH2 += 1;
                      if(alarmH2 == 24){
                          alarmH2 = 0;
                      }
                  }
              }
              if(alarm == 3){
                  alarmM2 += 1;
                  if(alarmM2 == 61){
                      alarmM2 = 1;
                  }
              }
              if(alarm == 4){
                offnum++;
                if(offnum%2==0){
                   offMessage2 = "ON";
                }
                else{
                    offMessage2 = "OFF";
                }
              }

           }

       }
       if(hour == 24){
           hour = 1;
       }

       if(pm == true){
           if(hour > 12){
               hour = 1;
           }
       }
       if(minute > 60){
           minute = 1;
       }

}
void myapp::func_btn_dwn(){
    init = 0;
    second = 0;
    if(alarmH1 == hour && alarmM1 == minute && alm1 == true){
        alm1 = false;
        emit sendMess5(QString(""));
        offMessage = "OFF";
        mediaPlayer->stop();
    }
    if(alarmH2 == hour && alarmM2 == minute && alm2 == true){
        alm2 = false;
        emit sendMess6(QString(""));
        offMessage2 = "OFF";
        mediaPlayer->stop();
    }
    //////////////////
        if(starter == true){
            if(change == 1){
                 hour -= 1;
            }
            else if(change == 2){
                minute -= 1;
            }
            else if(change == 3){
                apc--;
                if(apc%2==0){
                    format = true;
                    activator = true;
                }
                else {
                    format = false;
                }
            }
            else if(change == 4 && pm == true){
                ampm++;
                if(ampm%2==0){
                   amp2 = "AM";
                }
                else{
                    amp2 = "PM";
                }
            }
        }
        if(starter2 == true){
            if(alarm == 1){
                alnum++;
                if(alnum%2==0){
                   alset = 2;
                }
                else{
                    alset = 1;
                }
            }
            if(alset == 1){
                if(alarm == 2){
                   if(pm == true){
                      alarmH1 -= 1;
                      if(alarmH1 == 0){
                          alarmH1 = 12;
                      }
                   }
                   else if(pm == false){
                       alarmH1 -= 1;
                       if(alarmH1 == 0){
                           alarmH1 = 23;
                       }
                   }
               }
               if(alarm == 3){
                   alarmM1 -= 1;
                   if(alarmM1 < 0){
                       alarmM1 = 59;
                   }

               }
               if(alarm == 4){
                 offnum++;
                 if(offnum%2==0){
                    offMessage = "ON";
                 }
                 else{
                     offMessage = "OFF";
                 }
               }

            }
            else if(alset == 2){
                if(alarm == 2){
                   if(pm == true){
                      alarmH2 -= 1;
                      if(alarmH2 == 13){
                          alarmH1 = 1;
                      }
                   }
                   else if(pm == false){
                       alarmH2 -= 1;
                       if(alarmH2 == 24){
                           alarmH2 = 0;
                       }
                   }
               }
               if(alarm == 3){
                   alarmM2 -= 1;
                   if(alarmM2 < 0){
                       alarmM2 = 59;
                   }

               }
               if(alarm == 4){
                 offnum++;
                 if(offnum%2==0){
                    offMessage2 = "ON";
                 }
                 else{
                     offMessage2 = "OFF";
                 }
               }

            }

        }
        if(hour < 0){
            hour = 23;
        }
        if(minute < 0){
            minute = 59;
        }
}



















