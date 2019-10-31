MODULE DGPY ! ПОДГОТОВКА ДАННЫХ ДЛЯ ПОСТОРОЕНИЯ ГРАФИКОВ

IMPLICIT NONE

!**********************************************************************

INTEGER,                      PRIVATE :: KNL   =50     ! НОМЕР КАНАЛА ВЫВОДА ДАННЫХ
CHARACTER (LEN=2),            PRIVATE :: CHKNL ="50"   ! НОМЕР КАНАЛА ВЫВОДА ДАННЫХ
CHARACTER (LEN=3),            PRIVATE :: CHFT  ="svg"  ! ТИП ФАЙЛА РИСУНКА
CHARACTER (LEN=*), PARAMETER, PRIVATE :: CHDATA="#***" ! ИДЕНТИФИКАТОР БЛОКА ЧИСЛОВЫХ ДАННЫХ
CHARACTER (LEN=*), PARAMETER, PRIVATE :: PYTHON='python3.6 '
CHARACTER (LEN=*), PARAMETER, PRIVATE :: GFORT1='/home/evgeny/Dropbox/Проги/fortran/Roots/График/gfort1.py' 

!**********************************************************************

                  ! ПОДПРОГРАММЫ
PUBLIC  :: DGPYFT ! ИЗМЕНЕНИЕ ТИПА ФАЙЛА РИСУНКА
PUBLIC  :: DGPY11 ! ФОРМИРОВАНИЕ ЗАГОЛОВКА ФАЙЛА ДАННЫХ
PUBLIC  :: DGPY12 ! LEGEND ДЛЯ ДОПОЛНИТЕЛЬНОЙ КРИВОЙ НА ГРАФИКЕ
PUBLIC  :: DGPY1E ! ЗАПУСК НА ВЫПОЛНЕНИЕ ПРОГРАММЫ gfort1.py

!**********************************************************************

CONTAINS

!**********************************************************************

SUBROUTINE DGPYFT (CHFTYP) ! ТИП ФАЙЛА РИСУНКА

! ИЗМЕНЕНИЕ ТИПА ФАЙЛА РИСУНКА

CHARACTER (LEN=*), INTENT (IN) :: CHFTYP ! ТИП ФАЙЛА РИСУНКА

SELECT CASE(CHFTYP)

   CASE ("svg", "SVG")
      CHFT="svg"

   CASE ("png", "PNG")
      CHFT="png"

   CASE ("eps", "EPS")
      CHFT="eps"

   CASE ("pdf", "PDF")
      CHFT="pdf"

   CASE DEFAULT
      CHFT="svg"
      WRITE (3,'(/A/2A/A)')                                     &
      "РАБОТАЕТ МОДУЛЬ DGPY ПОДПРОГРАММА DGPYFT",               &
      "НЕПРАВИЛЬНО УКАЗАН ТИП ФАЙЛА РИСУНКА CHFTYP=", CHFTYP,   &
      "УСТАНОВЛЕН ТИП ФАЙЛА РИСУНКА ПО УМОЛЧАНИЮ - svg"

END SELECT

END SUBROUTINE DGPYFT

!**********************************************************************

SUBROUTINE DGPY11 (FLNAME, & ! ИМЯ ФАЙЛОВ ДАННЫХ И РИСУНКА
                   KANAL,  & ! НОМЕР КАНАЛА ВЫВОДА ДАННЫХ
                   TITLE,  & ! НАИМЕНОВАНИЕ РИСУНКА
                   XLABEL, & ! НАДПИСЬ X-ОСИ
                   YLABEL, & ! НАДПИСЬ Y-ОСИ
                   X1,     & ! LEFT ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
                   X2,     & ! RIGHT  ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
                   Y1,     & ! BOTTOM ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ Y
                   Y2,     & ! TOP    ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ Y
                   LEGEND)   ! LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ

! ФОРМИРОВАНИЕ ЗАГОЛОВКА ФАЙЛА ДАННЫХ

CHARACTER (LEN=*), INTENT (IN)           :: FLNAME ! ИМЯ ФАЙЛОВ ДАННЫХ И РИСУНКА
INTEGER,           INTENT (IN), OPTIONAL :: KANAL  ! НОМЕР КАНАЛА ВЫВОДА ДАННЫХ
CHARACTER (LEN=*), INTENT (IN), OPTIONAL :: TITLE  ! НАИМЕНОВАНИЕ РИСУНКА
CHARACTER (LEN=*), INTENT (IN), OPTIONAL :: XLABEL ! НАДПИСЬ X-ОСИ
CHARACTER (LEN=*), INTENT (IN), OPTIONAL :: YLABEL ! НАДПИСЬ Y-ОСИ
REAL,              INTENT (IN), OPTIONAL :: X1     ! LEFT   ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
REAL,              INTENT (IN), OPTIONAL :: X2     ! RIGHT  ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
REAL,              INTENT (IN), OPTIONAL :: Y1     ! BOTTOM ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ Y
REAL,              INTENT (IN), OPTIONAL :: Y2     ! TOP    ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ Y
CHARACTER (LEN=*), INTENT (IN), OPTIONAL :: LEGEND ! LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ

! НОМЕР КАНАЛА ВЫВОДА ДАННЫХ
IF ( PRESENT(KANAL) ) THEN
   IF ( ( KANAL < 20 ) .OR. ( KANAL > 99 ) ) THEN
      WRITE (3,'(/A/A,I0/A)')                                          &
      "РАБОТАЕТ МОДУЛЬ DGPY ПОДПРОГРАММА DGPY11",                      &
      "НЕПРАВИЛЬНО УКАЗАН НОМЕР КАНАЛА ВЫВОДА ДАННЫХ KANAL=", KANAL,   &
      "ВЫПОЛНЕНИЕ ПРОГРАММЫ ПРЕРВАНО"
      STOP
   ENDIF
   KNL=KANAL
   WRITE (CHKNL,'(I2)') KNL
END IF

! ИМЯ ФАЙЛОВ ДАННЫХ И РИСУНКА
WRITE (KNL,'(A)') FLNAME//'.'//CHFT

! НАИМЕНОВАНИЕ РИСУНКА
IF ( PRESENT(TITLE) ) THEN
    WRITE (KNL,'(A)') 'TITLE '//TITLE
END IF

! НАДПИСЬ X-ОСИ
IF ( PRESENT(XLABEL) ) THEN
    WRITE (KNL,'(A)') 'XLABEL '//XLABEL
END IF

! НАДПИСЬ Y-ОСИ
IF ( PRESENT(YLABEL) ) THEN
    WRITE (KNL,'(A)') 'YLABEL '//YLABEL
END IF

! LEFT ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
IF ( PRESENT(X1) ) THEN
    WRITE (KNL,'(A,E12.6)') 'XLEFT ', X1
END IF

! RIGHT ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ X
IF ( PRESENT(X2) ) THEN
    WRITE (KNL,'(A,E12.6)') 'XRIGHT ', X2
END IF

! BOTTOM ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ Y
IF ( PRESENT(Y1) ) THEN
    WRITE (KNL,'(A,E12.6)') 'YBOTTOM ', Y1
END IF

! TOP ГРАНИЦА ДИАПАЗОНА ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ Y
IF ( PRESENT(Y2) ) THEN
    WRITE (KNL,'(A,E12.6)') 'YTOP ', Y2
END IF

! ИДЕНТИФИКАТОР БЛОКА ЧИСЛОВЫХ ДАННЫХ + LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ
IF ( PRESENT(LEGEND) ) THEN
    WRITE (KNL,'(A)') CHDATA//' '//LEGEND
ELSE
    WRITE (KNL,'(A)') CHDATA ! БЕЗ ЛЕГЕНДЫ
END IF

END SUBROUTINE DGPY11

!**********************************************************************

SUBROUTINE DGPY12 (LEGEND)

CHARACTER (LEN=*), INTENT (IN), OPTIONAL :: LEGEND ! LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ

! ПЕЧАТЬ В ФАЙЛ ДАННЫХ
! ИДЕНТИФИКАТОР БЛОКА ЧИСЛОВЫХ ДАННЫХ + LEGEND ДЛЯ ПЕРВОЙ КРИВОЙ НА ГРАФИКЕ

IF ( PRESENT(LEGEND) ) THEN
    WRITE (KNL,'(A)') CHDATA//' '//LEGEND
ELSE
    WRITE (KNL,'(A)') CHDATA ! БЕЗ ЛЕГЕНДЫ
END IF

END SUBROUTINE DGPY12

!**********************************************************************

SUBROUTINE DGPY1E

! ЗАПУСК НА ВЫПОЛНЕНИЕ ПРОГРАММЫ gfort1.py

CLOSE(KNL)

CALL EXECUTE_COMMAND_LINE(PYTHON//GFORT1//' '//CHKNL) ! , WAIT=.FALSE.

END SUBROUTINE DGPY1E

!**********************************************************************

END MODULE DGPY
