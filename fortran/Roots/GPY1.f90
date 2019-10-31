PROGRAM GPY1

! ГРАФИКА PYTHON

USE DGPY ! ПОДГОТОВКА ДАННЫХ ДЛЯ ПОСТОРОЕНИЯ ГРАФИКОВ

!USE M_A

INTEGER, PARAMETER  :: KNL=55

INTEGER, PARAMETER  :: NP=10000

DIMENSION XXX(NP), YYY(NP)


! ******************************************************************************



!WRITE (3,'(A,I0)') ' A1=', A1
!WRITE (3,'(A,I0)') ' B1=', B1
!CALL M_AS1 ()
!WRITE (3,'(A,E12.6)') 'Q1_MAIN=', Q1
!CALL FFF1(QQ)
!WRITE (3,'(A,E12.6)') 'QQ=', QQ

CALL DGPYFT ("png") ! ТИП ФАЙЛА РИСУНКА

CALL DGPY11 ("QUUU",                        & ! ИМЯ ФАЙЛОВ ДАННЫХ И РИСУНКА
             KANAL=KNL,                     & ! НОМЕР КАНАЛА ВЫВОДА ДАННЫХ
             TITLE="НАИМЕНОВАНИЕ РИСУНКА",  & ! НАИМЕНОВАНИЕ РИСУНКА
             XLABEL="смещения $V_{1}$ тел", & ! НАДПИСЬ X-ОСИ
             YLABEL="Y-AXIS",               & ! НАДПИСЬ Y-ОСИ
             X1=-200000.0,                  & ! LEFT ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
             LEGEND="1wew")                   ! LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ

CALL SPECTRAL(KNL)
!DO LP=1,NP
!   XXX(LP)=LP* 110.0
!   YYY(LP)=LP*1100.0
!END DO


!DO LP=1,NP
!   WRITE (KNL,'(2E15.6)') XXX(LP), YYY(LP)
!END DO

!CALL DGPY12 (LEGEND="2ttt") ! LEGEND ДЛЯ ДОПОЛНИТЕЛЬНОЙ КРИВОЙ НА ГРАФИКЕ

!DO LP=1,NP/2
!   WRITE (KNL,'(2E15.6)') XXX(LP), YYY(LP)*2.0
!END DO

CALL DGPY1E ! ЗАПУСК НА ВЫПОЛНЕНИЕ ПРОГРАММЫ gfort1.py

!CALL EXECUTE_COMMAND_LINE(PYTHON//CHKNL) ! , WAIT=.FALSE.

! ******************************************************************************

CONTAINS

! ******************************************************************************

SUBROUTINE FFF1 (QQQ)

QQQ=QQQ+1.0

WRITE (3,'(A,E12.6)') 'QQQ=', QQQ

RETURN
END SUBROUTINE FFF1

! ******************************************************************************


END PROGRAM GPY1
