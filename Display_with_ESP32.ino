#include <Adafruit_GFX.h>        // Bibliothèque graphique de base (formes, texte, images)
#include <Adafruit_ST7789.h>     // Bibliothèque spécifique pour l'écran TFT avec contrôleur ST7789
#include "Logo.h"                // Fichier contenant le tableau de données de l'image (Logoimageslow)

#define TFT_CS 37                // Broche "Chip Select" du bus SPI pour l'écran
#define TFT_RST 39               // Broche "Reset" de l'écran
#define TFT_DC 38                // Broche "Data/Command" (indique si on envoie une commande ou des données)
#define TFT_MOSI 35              // Broche MOSI (Master Out Slave In) du bus SPI — envoi des données vers le TFT
#define TFT_SCLK 36              // Broche SCLK (horloge du bus SPI)

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);  // Création de l’objet écran avec les broches définies

const int IMAGE_WIDTH = 240;     // Largeur de l'image (en pixels)
const int IMAGE_HEIGHT = 133;    // Hauteur de l'image (en pixels)

void setup() {
  Serial.begin(9600);            // Démarrage de la communication série à 9600 bauds (pour le débogage)
  delay(1000);                   // Pause d’une seconde pour laisser le temps au matériel de s’initialiser

  tft.init(240, 320, SPI_MODE2); // Initialisation de l’écran TFT avec résolution 240x320 et mode SPI 2
  tft.setRotation(3);            // Définit l’orientation de l’écran (rotation de 270°)
  tft.fillScreen(ST77XX_BLACK);  // Remplit tout l’écran en noir (efface l’écran)
}

void loop() {
  // Calcule les coordonnées pour centrer l’image sur l’écran
  int x = (tft.width() - IMAGE_WIDTH) / 2;
  int y = (tft.height() - IMAGE_HEIGHT) / 2;

  // Affiche l’image (Logoimageslow) aux coordonnées (x, y)
  // avec la largeur et la hauteur spécifiées
  tft.drawRGBBitmap(x, y, Logoimageslow, IMAGE_WIDTH, IMAGE_HEIGHT);
}
