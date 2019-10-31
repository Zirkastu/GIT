PROGRAM GPY1

! ГРАФИКА PYTHON

USE DGPY ! ПОДГОТОВКА ДАННЫХ ДЛЯ ПОСТОРОЕНИЯ ГРАФИКОВ
USE spectralmethod

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
             TITLE="SIGMA(0,t)",  & ! НАИМЕНОВАНИЕ РИСУНКА
             XLABEL="t,c", & ! НАДПИСЬ X-ОСИ
             YLABEL="SIGMA,Па",               & ! НАДПИСЬ Y-ОСИ
             X1=0.0,       & ! LEFT ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X 
             X2=0.135E-02, & 
             LEGEND="Численное решение")                   ! LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ
CALL Spectral(KNL)
!DO LP=1,NP
!   XXX(LP)=LP* 110.0
!   YYY(LP)=LP*1100.0
!END DO


!DO LP=1,NP
!   WRITE (KNL,'(2E15.6)') XXX(LP), YYY(LP)
!END DO

CALL DGPY12 (LEGEND="Аналитическое решение") ! LEGEND ДЛЯ ДОПОЛНИТЕЛЬНОЙ КРИВОЙ НА ГРАФИКЕ

!DO LP=1,NP/2
!   WRITE (KNL,'(2E15.6)') XXX(LP), YYY(LP)*2.0
!END DO
WRITE (KNL,'(2E15.6)') 0.0, 0.0
WRITE (KNL,'(2E15.6)') 1/SQRT(2.1E11/7800), 0.0
WRITE (KNL,'(2E15.6)') 1/SQRT(2.1E11/7800), -2.0E6
WRITE (KNL,'(2E15.6)') 3/SQRT(2.1E11/7800), -2.0E6
WRITE (KNL,'(2E15.6)') 3/SQRT(2.1E11/7800), 0.0
WRITE (KNL,'(2E15.6)') 5/SQRT(2.1E11/7800), 0.0
WRITE (KNL,'(2E15.6)') 5/SQRT(2.1E11/7800), -2.0E6
WRITE (KNL,'(2E15.6)') 7/SQRT(2.1E11/7800), -2.0E6
WRITE (KNL,'(2E15.6)') 7/SQRT(2.1E11/7800), 0.0
WRITE (KNL,'(2E15.6)') 9/SQRT(2.1E11/7800), 0.0
WRITE (KNL,'(2E15.6)') 9/SQRT(2.1E11/7800), -2.0E6
WRITE (KNL,'(2E15.6)') 2E-3, -2.0E6
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
