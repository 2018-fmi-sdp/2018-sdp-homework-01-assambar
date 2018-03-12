# 2018 СДП - Домашно 01

***Ф№ 43753***

Оценката от домашното е 1/3 от оценката по ТКсем.

Задачите са две, като сумално дават 5 точки, еквивалентни на оценка от 2 до 7.

Крайна оценка по ТКсем над 6 ще бъде закръглена надолу до 6.

## Зад 1 (2.5 точки)
Да се напише команден интерпретатор, който използва REPL и поддържа следните команди:
 - `quit` - излиза от REPL и приключва изпълнението на програмата
 - `help` - отпечатва имената на всички поддържани команди по една на ред
 - `cmd.prompt <STRING>` - променя водещия текст на командния ред с подадения `<STRING>`
 - `asm.*` - набор от команди на прост асемблерен език, който поддържа 10 регистъра, събиране и изваждане на цели числа между -100 и 100. При стартиране на интерпретатора всички регистри имат стойност 0
   - `asm.reg.set <REG> <NUMBER>`
      - записва числото `<NUMBER>` в регистъра с номер `<REG>`
      - печата OK при успех или ERROR, ако `<REG>` не е между 0 и 9 или `<NUMBER>` не е между -100 и 100
   - `asm.reg.add <REG1> <REG2> <REG3>`
      - записва сумата на числата от регистри `<REG2>` и `<REG3>` в регистъра `<REG>`
      - печата OK при успех или ERROR, ако получената сума не е между -100 и 100
   - `asm.reg.dbg` - отпечатва стойностите на всички регистри по една на ред във вида `REG_# = <VALUE>`

За реализацията:
 - Всяка команда е на отделен ред
 - При четенето на нова команда интерпретаторът печата водещ текст (prompt), с който указва, че очаква вход 
 - За описание на командите да се използва базов клас Command, който има име и абстрактен виртуален метод `bool execute(const String& cmdLine, String* output)`, като когато методът върне `false` интерпретаторът приключва.
 - Интерпретаторът пази списък от указатели към Command инстанции в динамичната памет
 - Командите които ползват споделено състояние получават указател към него при конструирането си
 - Ето повърхностен дизайн описан с [PlantUml](https://www.planttext.com/?text=XLFHIiCm57tFLzp7hhEWhrB6P0eA8keUXuokkQkH9Yd9hGfp_swQjkbOtNmfkVUSd7Fk3PrRoWpLicGiBpDhOI7vWo8qbK7tXHq3I619HgW2rfNHiYBV4efWRR0Grj7iwkhopRSNMifCyHZMUNkogmQOmgSM70nMPJHnTJmGjqBnhd3GdZ6z-S2SWbbV1g_GwHqOEmeT9qOKxvGSK8uOILqbmM5qkyHjStbmx7VJgXqjHMKI_OWz73MTYMyLI4-ky3DFTzd6aibosc-qBe7hks_CQyAeKyebVnGABphb67HDLKtDKdhfz2VX-aiby58BShcXZtQFPTNKknEluDDqfEWFUC_26TBEewDVGvhM5cUpSOhUbOsXPxzR1x9kpK4s88Fm-FgDbQzOBB5L22yHH0xnCm5RsWtdPsLQ_5-PsqtXXpsfqn86dJagxdwjNm00)
 ![CmdInterpreter Design](https://www.planttext.com/plantuml/svg/XLFHIiCm57tFLzp7hhEWhrB6P0eA8keUXuokkQkH9Yd9hGfp_swQjkbOtNmfkVUSd7Fk3PrRoWpLicGiBpDhOI7vWo8qbK7tXHq3I619HgW2rfNHiYBV4efWRR0Grj7iwkhopRSNMifCyHZMUNkogmQOmgSM70nMPJHnTJmGjqBnhd3GdZ6z-S2SWbbV1g_GwHqOEmeT9qOKxvGSK8uOILqbmM5qkyHjStbmx7VJgXqjHMKI_OWz73MTYMyLI4-ky3DFTzd6aibosc-qBe7hks_CQyAeKyebVnGABphb67HDLKtDKdhfz2VX-aiby58BShcXZtQFPTNKknEluDDqfEWFUC_26TBEewDVGvhM5cUpSOhUbOsXPxzR1x9kpK4s88Fm-FgDbQzOBB5L22yHH0xnCm5RsWtdPsLQ_5-PsqtXXpsfqn86dJagxdwjNm00)

***Забележка***: Може да се използват наготово всякакви класове от примерните материали. Не се позволява използване на stl containers (включително std::string). Ако нещо ви потрябва, напишете си го сами.

## Зад 2 (2.5 точки)
Командният интерпретатор да се разшири със следните команди (името да е специфично с факултетния номер на студента, който ги имплементира)
 - `fn#####.*` - набор от команди реализирани от студента с факултетен номер ##### (например fn22707.info е команда info реализирана от студент с номер 22707). Командит
   - `fn#####.info` - отмечатва име, специалност и година на записване на студента
   - `fn#####.sdp.*` - набор от команди които дават върможност за за писване и пресмятане на оценките на студента по СДП
   - `fn#####.sdp.info` - отпечатва формулата по която се смятат оценките по СДП (качена в moodle страницата на курса), както и правилата за освобождаване
   - `fn#####.sdp.marks` - отпечатва стойността на всеки от параметрите определящи оценката по СДП като резултатът съдържа следните редове:
      ```
      TKsem = <value>
      Kt01 = <value>
      Kt02 = <value>
      Kz01 = <value>
      Kz02 = <value>
      TK = <value>
      It = <value> (Can skip? {yes = <skipvalue> | no})
      Iz = <value> (Can skip? {yes = <skipvalue> | no})
      I = <value> (Skip T? {yes = <skipvalue> | no}), Skip Z? {yes = <skipvalue> | no}), Skip Both? {yes = <skipvalue> | no}))
      O = <value> (Skip T? {yes = <skipvalue> | no}), Skip Z? {yes = <skipvalue> | no}), Skip Both? {yes = <skipvalue> | no}))       
      Skip with Average? {yes | no}
      ```
      Където `<value>` е оценка 2-6, `<skipvalue>` e оценка 
   - `fn#####.sdp.TKsem <value>`
     - запазва `<value>` (2-6) като оценка от семинарните упражнения.
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.Kt01 <value>`
     - запазва `<value>` (2-6) като оценка от първото контролно теория
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.Kt02 <value>`
     - запазва `<value>` (2-6) като оценка от второто контролно теория
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.Kz01 <value>`
     - запазва `<value>` (2-6) като оценка от първото контролно задачи
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.Kz02 <value>`
     - запазва `<value>` (2-6) като оценка от второто контролно задачи
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.Iz <value>`
     - запазва `<value>` (2-6) като оценка от изпит задачи
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.It <value>`
     - запазва `<value>` (2-6) като оценка от изпит теория
     - печата OK при успех или ERROR, ако `<value>` не е между 2 и 6
   - `fn#####.sdp.SemAttendance <value>`
     - запазва `<value>` (0-100) като процент присъствия на семинарите
     - печата OK при успех или ERROR, ако `<value>` не е между 0 и 100
   - `fn#####.sdp.PracticeAttendance <value>`
     - запазва `<value>` (0-100) като процент присъствия на практикумите
     - печата OK при успех или ERROR, ако `<value>` не е между 0 и 100
   - `fn#####.sdp.PracticePass <value>`
     - запазва `<value>` (true|false) като оценка да/не от практикумите
     - печата OK при успех или ERROR, ако `<value>` е различна от "true" или "false"
