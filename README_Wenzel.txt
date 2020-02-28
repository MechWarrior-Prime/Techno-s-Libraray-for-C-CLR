Hallo Frank,
har ein wenig gedauert, aber ich habe das Problem gefunden!

Dein technolib-Projekt hatte als Projektvorlage "CLR Klassenbibliothek für .NET CORE",
		 das Taschenrechenr Projekt allerdings "CLR Projekt für .NET FrameWork"

Die beiden Dinge passen nicht zusammen, bzw. wurden dann weitere Abhängigkeiten aus dem .NET Core erwartet..

Hier die "korrigierte" Version, die ich als .NET Framework Projekt neu angelegt habe und den Quellcode übernommen.
Diese x64 .dll konnte ich erfolgreich im Taschenrechner Projekt als Verweis einbinden und benutzen.

Viele Grüße, und einen schönen Abend, Wenzel