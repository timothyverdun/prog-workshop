# WORKSHOP PROG & ALGO - Timothy Verdun

## Projet global 
Après avoir commencé les premiers exercices en créant une nouvelle fonction que j'appelais ensuite dans main à chaque fois, je me suis dit qu'il serait intéréssant de proposer un "menu" à l'utilisateur pour lui permettre de choisir simplement l'image et l'effet à appliquer. 
En faisant ça, j'ai fait plusieurs ajustements sur mes fonctions pour qu'elles soient plus flexibles et polyvalentes.

## Exercice 1 : Onlygreen
| Avant | Après |
| :---: | :---: |
| ![logo imac](images/logo.png) | ![logo-onlygreen](output/onlygreen.png) |

## Exercice 2 : Noir et blanc
| Avant | Après |
| :---: | :---: |
| ![logo imac](images/logo.png) | ![blackandwhite](output/blackandwhite.png) |

## Exercice 3 : Négatif
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![negative](output/negative.png) |

## Exercice 4 : Dégradé
| Avant | Après |
| :---: | :---: |
| — | ![degrade](output/degrade.png) |

## Exercice 5 : Miroir
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![miror](output/miror.png) |

## Exercice 6 : Bruit
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![noise](output/noise.png) |

## Exercice 7 : Rotation à 90°
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![rotate90](output/rotate90.png) |

## Exercice 8 : RGB Split
| Avant | Après |
| :---: | :---: |
| ![logo imac](images/logo.png) | ![rgbsplit](output/rgbsplit.png) |

## Exercice 9 : Luminosité
On demande à l'utilisateur une valeur de luminosité à partir de 0. (0 le plus clair, 2 plus foncé). Exemple avec lum_value = 0.5 :
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![lum](output/lum.png) |

## Exercice 10 : Disque
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![disk](output/disk.png) |

## Exercice 11 : Cercle
On dessine un cercle centré sur une image et on demande à l'utilisateur l'épaisseur du trait. Exemple avec thickness = 30 :
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![circle](output/circle.png) |

## Exercice 12 : Rosace
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![rosace](output/rosace.png) |

## Exercice 13 : Rétrécir l'image (`smallimg`)
On demande à l'utilisateur une valeur (entière) de réduction de l'image. Exemple avec une image 3 fois plus petite (div_size = 3) :
| Avant | Après |
| :---: | :---: |
| ![logo imac](images/logo.png) | ![smallimg](output/smallimg.png) |

## Exercice 14 : Mosaïque (`mosaic`)
On demande à l'utilisateur la taille de la mosaïque. Exemple avec une mosaïque de 4x4 (size = 4) :
| Avant | Après |
| :---: | :---: |
| ![logo imac](images/logo.png) | ![mosaic](output/mosaic.png) |

## Exercice 15 : Glitch
On demande à l'utilisateur la valeur du glitch. Exemple avec gain=60 (on fait 60 glitchs) :
| Avant | Après |
| :---: | :---: |
| ![photo](images/photo.jpg) | ![glitch](output/glitch.png) |

## Exercice 16 : Tri des pixels (`sortpixels`)
Tri horizontal des pixels.
| Avant | Après |
| :---: | :---: |
| ![logo imac](images/logo.png) | ![sortedpixels](output/sortedpixels.png) |
*Ici j'ai d'abord essayer de coder la méthode classique mais j'obtenait simplement une image avec 2 bandes colorées. J'ai donc préféré utiliser std::sort qui est bien plus simple et efficace.