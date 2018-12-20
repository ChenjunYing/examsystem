/*
Navicat MySQL Data Transfer

Source Server         : 3300
Source Server Version : 80013
Source Host           : localhost:3300
Source Database       : examsystem

Target Server Type    : MYSQL
Target Server Version : 80013
File Encoding         : 65001

Date: 2018-12-20 23:24:13
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `admin`
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `privilege` int(1) NOT NULL DEFAULT '0',
  `department` varchar(30) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('1', 'admin', 'admin', '0', '0');

-- ----------------------------
-- Table structure for `config`
-- ----------------------------
DROP TABLE IF EXISTS `config`;
CREATE TABLE `config` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `start_time` datetime DEFAULT NULL,
  `end_time` datetime DEFAULT NULL,
  `object_score` int(5) DEFAULT '0',
  `multi_score` int(5) DEFAULT NULL,
  `judge_score` int(5) DEFAULT '0',
  `is_submit` int(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `username` (`username`),
  KEY `exam_code` (`exam_code`),
  CONSTRAINT `config_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `config_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of config
-- ----------------------------
INSERT INTO `config` VALUES ('1', 'test', '1', null, null, '60', null, '40', '1');
INSERT INTO `config` VALUES ('2', 'test', '3', null, null, '0', null, '0', '0');

-- ----------------------------
-- Table structure for `exam`
-- ----------------------------
DROP TABLE IF EXISTS `exam`;
CREATE TABLE `exam` (
  `exam_code` int(5) NOT NULL AUTO_INCREMENT,
  `exam_name` varchar(40) NOT NULL,
  `start_time` datetime DEFAULT NULL,
  `end_time` datetime DEFAULT NULL,
  `duration` int(5) NOT NULL,
  `information` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`exam_code`),
  UNIQUE KEY `exam_code` (`exam_code`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of exam
-- ----------------------------
INSERT INTO `exam` VALUES ('1', '《面向对象程序设计》课程期末考试', null, null, '120', '信息1');
INSERT INTO `exam` VALUES ('2', '《数据结构基础》课程期末考试', null, null, '90', '信息2');
INSERT INTO `exam` VALUES ('3', '一场简单的小测试', null, null, '100', '简单');

-- ----------------------------
-- Table structure for `exam_content`
-- ----------------------------
DROP TABLE IF EXISTS `exam_content`;
CREATE TABLE `exam_content` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `object_id` int(5) DEFAULT NULL,
  `judge_id` int(5) DEFAULT NULL,
  `exam_code` int(5) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `object_id` (`object_id`),
  KEY `subject_id` (`judge_id`),
  KEY `exam_code` (`exam_code`),
  CONSTRAINT `exam_content_ibfk_1` FOREIGN KEY (`object_id`) REFERENCES `object_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `exam_content_ibfk_2` FOREIGN KEY (`judge_id`) REFERENCES `judge_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `exam_content_ibfk_3` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of exam_content
-- ----------------------------

-- ----------------------------
-- Table structure for `judge_answer`
-- ----------------------------
DROP TABLE IF EXISTS `judge_answer`;
CREATE TABLE `judge_answer` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `question_id` int(5) NOT NULL,
  `answer` varchar(1000) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `username` (`username`),
  KEY `exam_code` (`exam_code`),
  KEY `question_id` (`question_id`),
  CONSTRAINT `judge_answer_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `judge_answer_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `judge_answer_ibfk_3` FOREIGN KEY (`question_id`) REFERENCES `judge_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of judge_answer
-- ----------------------------

-- ----------------------------
-- Table structure for `judge_question`
-- ----------------------------
DROP TABLE IF EXISTS `judge_question`;
CREATE TABLE `judge_question` (
  `question_id` int(5) NOT NULL AUTO_INCREMENT,
  `description` varchar(800) NOT NULL,
  `answer` varchar(5) NOT NULL,
  `value` int(3) NOT NULL,
  `author` varchar(20) NOT NULL,
  PRIMARY KEY (`question_id`),
  UNIQUE KEY `question_id` (`question_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of judge_question
-- ----------------------------
INSERT INTO `judge_question` VALUES ('1', '这道题的答案是错误的', 'F', '1', 'admin');
INSERT INTO `judge_question` VALUES ('2', '添加一个判断题', 'F', '1', 'admin');

-- ----------------------------
-- Table structure for `object_answer`
-- ----------------------------
DROP TABLE IF EXISTS `object_answer`;
CREATE TABLE `object_answer` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `question_id` int(5) NOT NULL,
  `answer` varchar(5) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `username` (`username`),
  KEY `exam_code` (`exam_code`),
  KEY `question_id` (`question_id`),
  CONSTRAINT `object_answer_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `object_answer_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `object_answer_ibfk_3` FOREIGN KEY (`question_id`) REFERENCES `object_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of object_answer
-- ----------------------------

-- ----------------------------
-- Table structure for `object_question`
-- ----------------------------
DROP TABLE IF EXISTS `object_question`;
CREATE TABLE `object_question` (
  `question_id` int(5) NOT NULL AUTO_INCREMENT,
  `description` varchar(800) NOT NULL,
  `A` varchar(500) DEFAULT NULL,
  `B` varchar(500) DEFAULT NULL,
  `C` varchar(500) DEFAULT NULL,
  `D` varchar(500) DEFAULT NULL,
  `answer` varchar(5) NOT NULL,
  `value` int(3) NOT NULL,
  `type` int(1) NOT NULL DEFAULT '0',
  `author` varchar(20) NOT NULL,
  PRIMARY KEY (`question_id`),
  UNIQUE KEY `question_id` (`question_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of object_question
-- ----------------------------
INSERT INTO `object_question` VALUES ('1', '下列哪个不是hlh的外号', '胡唱歌', 'gg', 'cg天才红娘', '舞女', 'C', '2', '0', 'admin');
INSERT INTO `object_question` VALUES ('2', '1+1=？', '1', '2', '3', '4', 'B', '2', '0', 'admin');
INSERT INTO `object_question` VALUES ('3', '这道题答案是C', '这道题答案是B', '这道题答案是D', '这道题答案是A', '这道题答案是C', 'C', '2', '0', 'admin');
INSERT INTO `object_question` VALUES ('4', '多选题，你猜选什么', 'AA', 'BB', 'CC', 'DD', 'ABCD', '3', '1', 'admin');
INSERT INTO `object_question` VALUES ('5', '下列哪些是ch的外号', '欢哥', 'cg天才少女', 'cg天才红娘', 'chdltql', 'ABC', '4', '1', 'admin');
INSERT INTO `object_question` VALUES ('6', '这是一道很长的题目这是一道很长的题目这是一道很长的题目这是一道很长的题目这是一道很长的题目这是一道很长的题目', '它真的很长', '它真的很长它真的很长它真的很长它真的很长它真的很长', '它真的很长它真的很长它真的很长它真的很长它真的很长它真的很长', '它真的很长它真的很长它真的很长它真的很长', 'C', '100', '0', 'admin');
INSERT INTO `object_question` VALUES ('8', '这道题有四个答案', '这是答案', '这是答案', '这是答案', '这也是答案', 'ABCD', '4', '1', 'admin');

-- ----------------------------
-- Table structure for `score`
-- ----------------------------
DROP TABLE IF EXISTS `score`;
CREATE TABLE `score` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `subject_id` int(5) NOT NULL,
  `subject_score` int(3) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`) USING BTREE,
  UNIQUE KEY `exam_code` (`exam_code`) USING BTREE,
  UNIQUE KEY `subject_id` (`subject_id`) USING BTREE,
  CONSTRAINT `score_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `score_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `score_ibfk_3` FOREIGN KEY (`subject_id`) REFERENCES `judge_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of score
-- ----------------------------

-- ----------------------------
-- Table structure for `user`
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `privilege` int(1) NOT NULL DEFAULT '0',
  `person_name` varchar(15) NOT NULL,
  `major` varchar(10) NOT NULL,
  `phone_number` varchar(15) NOT NULL,
  `sex` int(1) NOT NULL DEFAULT '0',
  `student_id` varchar(15) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('1', 'test', '123', '0', '嘤菜鸡', 'SoftWare', '12345678901', '0', '3170100000');
