# Dustin Follett Track Meet DataBase

use dbFollettTrack;

#Drop Table Results;
#Drop Table Athlete;
#Drop Table Eventss;
#Drop Table School;
#Drop Table ScoreBoard;

#Drop PROCEDURE enterAthlete;
#Drop PROCEDURE enterResult;
#Drop PROCEDURE dqEvent;
#Drop PROCEDURE dqMeet;
#Drop PROCEDURE scoreTrack;
#Drop PROCEDURE scoreField;
#DROP PROCEDURE dqPlayers;
#DROP PROCEDURE scoreSchools;

CREATE PROCEDURE enterAthlete (fname varchar(20), lname varchar(20), gen varchar(20), schoId varchar(20))
insert into Athlete(FirstName,LastName,Gender,SchoolId)
values(fname,lname,gen,schoId);

CREATE PROCEDURE DqEvent (athId int,eventId int)
update Results 
set DisQualified = 'True'
where Results.athId = athId and Results.eventId = eventId;

CREATE PROCEDURE DqMeet (athId int)
update Athlete
set athTooManyEventsDqed = 'True'
where Athlete.athId = athId;

delimiter //

CREATE PROCEDURE scoreTrack (eventNumber int)
begin
 DECLARE i INT;
 DECLARE rId INT;
 DECLARE p INT;
 set i = 0;
 while i <= 6
 DO
 SET rId = (SELECT resultId FROM Results WHERE EventId=eventNumber and Disqualified != 'True' ORDER BY Result ASC LIMIT i,1);
 IF i = 0 THEN SET p = 10; end if;
 IF i = 1 THEN SET p = 8; end if;
 IF i = 2 THEN SET p = 6; end if;
 IF i = 3 THEN SET p = 4; end if;
 IF i = 4 THEN SET p = 2; end if;
 IF i = 5 THEN SET p = 1; end if;
 IF i >= 6 THEN SET p = 0; end if;

UPDATE Results 
SET 
    Points = p
WHERE
    resultId = rId;
UPDATE Results 
SET 
    Place = i + 1
WHERE
    resultId = rId;
 SET i = i + 1;
 END WHILE;
 END //

delimiter ;

delimiter //

CREATE PROCEDURE scoreField(eventNumber int)
begin
 DECLARE i INT;
 DECLARE rId INT;
 DECLARE p INT;
 SET i = 0;
 while i <= 6
 DO
 SET rId = (SELECT resultId FROM Results WHERE EventId=eventNumber ORDER BY Result DESC LIMIT i,1);
 IF i = 0 THEN SET p = 10; END IF;
 IF i = 1 THEN SET p = 8; END IF;
 IF i = 2 THEN SET p = 6; END IF;
 IF i = 3 THEN SET p = 4; END IF;
 IF i = 4 THEN SET p = 2; END IF;
 IF i = 5 THEN SET p = 1; END IF;
 IF i >= 6 THEN SET p = 0; END IF;

UPDATE Results 
SET 
    Points = p
WHERE
    resultId = rId;
UPDATE Results 
SET 
    Place = i + 1
WHERE
    resultId = rId;
 SET i = i + 1;
 END WHILE;
 END//
 
 delimiter ;
 
delimiter //
CREATE PROCEDURE dqPlayers()
 BEGIN
  DECLARE i INT;
  DECLARE rId INT;
  DECLARE p INT;
  DECLARE j INT;
  SET j = (SELECT COUNT(DISTINCT resultId) from Results);
  SET i = (Select athId from Results where resultId = @j);
  WHILE j!=0
   DO
   UPDATE Athlete
   SET EventCount = EventCount + 1
   where athId = i;
   SET j = j - 1;  
  END WHILE;
 END//
 
 delimiter ;
 

CREATE PROCEDURE scoreSchools(Ppoints int,SschoolId int)
UPDATE ScoreBoard
SET points = Ppoints
where schoolId = SschoolId;


CREATE TABLE School (
    schoolId INT NOT NULL UNIQUE,
    schoolName VARCHAR(20) UNIQUE,
    state VARCHAR(20),
    points INT,
    PRIMARY KEY (schoolId)
);

CREATE TABLE ScoreBoard (
    place INT,
    schoolId int,
    school VARCHAR(20),
    points INT);

CREATE TABLE Athlete (
    FirstName VARCHAR(20),
    LastName VARCHAR(20),
    Gender VARCHAR(1),
    SchoolId INT,
    EventCount INT DEFAULT 0,
    athId INT NOT NULL UNIQUE AUTO_INCREMENT,
    athTooManyEventsDqed VARCHAR(5),
    CONSTRAINT un_Names UNIQUE (SchoolId , FirstName),
    PRIMARY KEY (athId),
    FOREIGN KEY (SchoolId)
        REFERENCES School (schoolId)
);

CREATE TABLE Eventss (
    eventId INT NOT NULL UNIQUE,
    eventName VARCHAR(20),
    eventGender VARCHAR(1),
    eventType ENUM('Track', 'Field'),
    PRIMARY KEY (eventId)
);

CREATE TABLE Results (
    resultId INT NOT NULL UNIQUE AUTO_INCREMENT,
    athId INT,
    Place INT,
    First VARCHAR(10),
    Last VARCHAR(10),
    EventId INT,
    Event VARCHAR(25),
    Result FLOAT,
    Points INT,
    School VARCHAR(20),
    Gender VARCHAR(1),
    Disqualified VARCHAR(5),
    FOREIGN KEY (athId)
        REFERENCES Athlete (athId),
    FOREIGN KEY (EventId)
        REFERENCES Eventss (eventId)
);

#this trigger increments the event count and once the event count exceeds 4 id marks them as dqed in the athlete table
# works but not in unision with stored procedure for entering results. have to dq them manually.
#delimiter //
#	create trigger athEventCountDq
#		after insert on Results
#		for each row
#		begin update Athlete
#			set EventCount = EventCount+1
#			where Athlete.athId = new.athId;
			
#		update Athlete
#			set athTooManyEventsDqed = 'True'
#			where Athlete.athId = new.athId && Athlete.EventCount > 3;
#end//
#delimiter ;

CREATE PROCEDURE enterResult (athId int,eventId int,result VarChar(8))
insert into Results(athId, Place, First, Last, EventId, Event, Result, Points, School, Gender, Disqualified)
values(athId,0,(select a.FirstName from Athlete a where a.athId = athId),(select a.LastName from Athlete a where a.athId = athId),eventId,(select e.eventName from Eventss e where eventId = e.eventId),result,0,(select s.schoolName from School s, Athlete a where s.schoolId = a.SchoolId and a.athId = athId),(select a.Gender from Athlete a where a.athId = athId),'false');

insert into School(schoolId, schoolName, state,points)
values(1, 'Elk Meadow HS', 'Oregon',0),
(2, 'High Desert HS', 'California',0),
(3, 'Summit HS', 'Idaho',0),
(4, 'Bend HS', 'Oregon',0),
(5, 'Eastern Oregon HS', 'Oregon',0); 

insert into Athlete(FirstName, LastName, Gender, SchoolId)
values('Tom', 'Dooley', 'M', 1),
('Marge', 'Simpson', 'F', 2),
('Juan', 'Drake', 'M', 3),
('Tywaina', 'Bannister', 'F', 4),
('Alexios', 'Dean', 'M', 5),
('Stella', 'McQueen', 'F', 1),
('Wade', 'Watts', 'M', 2),
('June', 'Sparrow', 'F', 3),
('Parcival', 'Artimis', 'M', 4),
('Janice', 'Johnson', 'F', 5),
('John', 'Frank', 'M', 1),
('Jeff', 'Senatra', 'M', 2),
('Willy', 'Nelson', 'M', 3),
('Jamie', 'Stanfield', 'F', 4),
('Earl', 'Haggard', 'M', 5),
('Micah', 'Troutman', 'F', 1),
('Audrey', 'Anolfo', 'F', 2),
('Erin', 'Kelly', 'F', 3),
('Vin', 'Diesel', 'M', 4),
('Fatima', 'Ortega', 'F', 5),
('Alex', 'Farmer', 'M', 1),
('Pam', 'Day', 'F', 2),
('Sage', 'Farnsworth', 'M', 3),
('Makayla', 'Adams', 'F', 4),
('Jake', 'Sexton', 'M', 5),
('Jess', 'Mink', 'F', 1),
('Dave', 'Hester', 'M', 2),
('Andrea', 'Willson', 'F', 3),
('Darwin', 'Prince', 'M', 4),
('Kelsey', 'Smart', 'F', 5);

insert into Eventss(eventId, eventName, eventGender, eventType)
values(1,'100 Meter Sprint','M', 'Track'),
(2, '100 Meter Sprint', 'F', 'Track'),
(3, 'Javlin', 'M', 'Field'),
(4, 'Javlin', 'F', 'Field'),
(5, 'Long Jump', 'M', 'Field'),
(6, 'Long Jump', 'F', 'Field'),
(7,'4x4', 'M', 'Track'),
(8,'4x4', 'F', 'Track'),
(9,'PoleVault','M','Field'),
(10,'PoleVault','F','Field');

insert into Results(athId, Place, First, Last, EventId, Event, Result, Points, School, Gender, Disqualified)
values(1,0,'Tom','Dooly',1,'100 Meter Sprint',15.7,0,'Elk Meadow HS', 'M', 'false'),
(1,0,'Tom','Dooly',1,'100 Meter Sprint',12.2,0,'Elk Meadow HS', 'M', 'false'),
(1,0,'Tom','Dooly',1,'100 Meter Sprint',11.7,0,'Elk Meadow HS', 'M', 'false'),
(1,0,'Tom','Dooly',1,'100 Meter Sprint',17.1,0,'Elk Meadow HS', 'M', 'false'),
(2,0,'Marge','Simpson',6,'Long Jump',19.2,0,'High Desert HS', 'F', 'false'),
(2,0,'Marge','Simpson',2,'100 Meter Sprint',14.7,0,'High Desert HS', 'F', 'false'),
(3,0,'Juan','Drake',3,'Javlin',150.1,0,'Summit HS', 'M', 'false'),
(4,0,'Tywaina','Bannister',6,'Long Jump',10.9,0,'Bend HS', 'F', 'false'),
(5,0,'Alexios','Dean',5,'Long Jump',25.0,0,'Eastern Oregon HS', 'M', 'false'),
(6,0,'Stella','McQueen',8,'4x4',50.1,0,'Elk Meadow HS', 'F', 'false'),
(7,0,'Wade','Watts',9,'PoleVault',15.7,0,'High Desert HS', 'M', 'false'),
(8,0,'June','Sparrow',10,'PoleVault',19.0,0,'Summit HS', 'F', 'false'),
(9,0,'Parcival','Artimis',1,'100 Meter Sprint',17.7,0,'Bend HS', 'M', 'false'),
(10,0,'Janice','Johnson',4,'Javlin',170.0,0,'Eastern Oregon HS', 'F', 'false'),
(11,0,'John','Frank',4,'Javlin',110.7,0,'Elk Meadow HS', 'M', 'false'),
(12,0,'Jeff','Senatra',4,'Javlin',200.1,0,'High Desert HS', 'M', 'false'),
(13,0,'Willy','Nelson',3,'Javlin',250.9,0,'Summit HS', 'M', 'false'),
(14,0,'Jamie','Stanfield',6,'Long Jump',19.9,0,'Bend HS', 'F', 'false'),
(15,0,'Earl','Haggard',3,'Javlin',226.1,0,'Eastern Oregon HS', 'M', 'false'),
(16,0,'Micah','Troutman',4,'Javlin',101.1,0,'Elk Meadow HS', 'F', 'false'),
(17,0,'Audrey','Anolfo',6,'Long Jump',20.0,0,'High Desert HS', 'F', 'false'),
(18,0,'Erin','Kelly',8,'4x4',15.7,0,'Summit HS', 'F', 'false'),
(19,0,'Vin','Diesel',1,'100 Meter Sprint',10.8,0,'Bend HS', 'M', 'false'),
(20,0,'Fatima','Ortega',10,'PoleVault',10.9,0,'Eastern Oregon HS', 'F', 'false'),
(21,0,'Alex','Farmer',1,'100 Meter Sprint',10.9,0,'Elk Meadow HS', 'M', 'false'),
(22,0,'Pam','Day',2,'100 Meter Sprint',12.1,0,'High Desert HS', 'F', 'false'),
(23,0,'Sage','Farnsworth',3,'Javlin',199.5,0,'Summit HS', 'M', 'false'),
(24,0,'Makayla','Adams',4,'Javlin',99.9,0,'Bend HS', 'F', 'false'),
(25,0,'Jake','Sexton',5,'Long Jump',10.9,0,'Eastern Oregon HS', 'M', 'false'),
(26,0,'Jess','Mink',6,'Long Jump',16.6,0,'Elk Meadow HS', 'F', 'false'),
(27,0,'Dave','Hester',7,'4x4',70.9,0,'High Desert HS', 'M', 'false'),
(28,0,'Andrea','Willson',8,'4x4',49.0,0,'Summit HS', 'F', 'false'),
(29,0,'Darwin','Prince',9,'PoleVault',20.0,0,'Bend HS', 'M', 'false'),
(30,0,'Kelsey','Smart',10,'PoleVault',19.1,0,'Eastern Oregon HS', 'F', 'false');

insert into ScoreBoard(place,schoolId,school,points)
values(0,1,'Elk Meadow HS',0),
(0,2,'High Desert HS',0),
(0,3,'Summit HS',0),
(0,4,'Bend HS',0),
(0,5,'Eastern Oregon HS',0);

#select * from School;
#select * from Athlete;
#select * from Eventss;
#select * from Results;


