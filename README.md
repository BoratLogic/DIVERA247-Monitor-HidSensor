<!---
![GitHub License](https://img.shields.io/github/license/:user/:repo) ![GitHub Release](https://img.shields.io/github/v/release/:user/:repo) ![GitHub issue/pull request detail](https://img.shields.io/github/:issueKind/detail/:property/:user/:repo/:number) -->
# DIVERA247-Monitor-HidSensor
Das **Projekt DIVERA247-Monitor-HidSensor** stellt ein USB HID (Human Interface Device) als Tasterbox mit Bewegungsmelder bereit, um deinen Divera 24/7 Monitor zu steuern.

## Was kann die HIDSensor Box?
Aufwecken deines Monitor Computers aus dem Bildschirmschoner, durch Tastendruck oder Bewegung. Neustarts des Computers durch einen langen Tastendruck.
**Vorteil**; es ist keine Netzwerkonfiguration oder Treiber Installation erforderlich. Die Tastebox wird automatisch als USB HID (Human Interface Device) Gerät erkannt und ist mit den vorinstallierten Treibern aller Betriebssystemen kompatibel.
  
## Hardware
### Stückliste
#### Notwendig
- 1x [Leuchtdrucktaster (optional auch mehrere möglich)](https://www.amazon.de/dp/B088CNW12P)
- 1x [SR602 Infrarot Bewegungssensor](https://www.amazon.de/gp/product/B07XG734RZ)
- 1x Arduino kompatibles *Atmega32U4* Entwicklerboard (Ardiono Micro; [DUBEUYEW Pro Micro Atmega32U4](https://www.amazon.de/dp/B0B7KXZN1D); o.ä.)
- 1x [Micro USB Kabel](https://www.amazon.de/dp/B09983XPM9)
- 1x [Kunststoffgehäuse](https://pages.github.com/)
#### Optional
- 1x [Gummidurchführung](https://www.amazon.de/gp/product/B0919FYWQ1)
### Pläne
#### Breadboard
<div style="width:200px;">

![Bild der Breadboardansicht](/doc/schematic/DIVERA247-Monitor-HidSensor_schematic_Breadboard.png "Breadboard ansicht")
</div>

#### Schaltplan
<div style="width:200px;">

![Bild des Schaltplans](/doc/schematic/DIVERA247-Monitor-HidSensor_schematic_Schaltplan.png "Schaltplan")
</div>

#### Verdrahtung
<div style="width:200px;">

![Bild des Schaltplans](/doc/schematic/DIVERA247-Monitor-HidSensor_schematic.png "Schaltplan")
</div>

### Gehäuse

Bohrschablone ist im Aufkleber integriert
<p>
<img src="/doc/aufkleber/aufkleber.svg" width="100" height="100"/>

<div style="width:30">

![Bild des Schaltplans](/doc/aufkleber/aufkleber.svg "Schaltplan")

</div>

## Software
Installation des Codes auf dem Arduino via PlatformIO (GitHub Projekt öffnen)

ODER

via WebInstaller, hiermit ist keine Installation von Software auf deinem Computer nötig.

## Betriebssystem einrichten
Als Tastatur emulation wird bei Bewegung oder kurzem Tasterdruck die <kbd>Rollen</kbd> Taste gedrückt. Bei einem langen Tastendruck wird <kbd>Strg</kbd> + <kbd>Alt</kbd> + <kbd>r</kbd> kurz gedrückt gehalten.

Somit muss der Tastatur Kurzbefehl nurnoch im Betriebssystem angelegt werden.

Unter **Ubuntu** ist es mit dieser [Anleitung](https://help.ubuntu.com/stable/ubuntu-help/keyboard-shortcuts-set.html.de#:~:text=Klicken%20Sie%20auf%20Einstellungen.,geben%20Sie%20einen%20Suchbegriff%20ein.) möglich. Als Befehl muss ```sudo shutdown -r now``` festgelegt werden.

Unter **Windows** eine Desktopverknüpfung anlegen und Anschließend das Eigenschaften Fenster öffnen, sobald der Cursor im Feld *Tastenkombination* ist auf der Tastatur <kbd>Strg</kbd> + <kbd>Alt</kbd> + <kbd>r</kbd> drücken. Jetzt nurnoch die Änderung speichern.

