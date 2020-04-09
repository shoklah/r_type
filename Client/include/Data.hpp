/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** All structs
*/

#pragma once

#define HELLO_FROM_CLIENT 0x0A
#define HELLO_FROM_SERVER 0x0B
#define START_GAME 0x0C
#define KEY_EVENT 0x04
#define CREATE_ENTITY 0x01
#define MOVE_ENTITY 0x02
#define DIE_ENTITY 0x03

struct connection_t {
  char opcode;
};

struct attack_t {
  char opcode;
  int idPlayer;
  int power;
};

struct create_t {
  char opcode;
  int idEntity;
  int typeEntity;
  int x;
  int y;
};

struct die_t {
  char opcode;
  int idPlayer;
};

struct t_key {
  char opcode;
  int Playerid;
  int key;
};

struct move_t {
  char opcode;
  int idEntity;
  int x;
  int y;
};

struct newGame_t {
  char opcode;
  int id;
};