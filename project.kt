package com.example.demo.models

import jakarta.persistence.*
import org.graalvm.nativeimage.c.struct.UniqueLocationIdentity
import org.intellij.lang.annotations.Identifier
import java.time.LocalDate
import javax.annotation.processing.Generated

enum class Position {psychologist, moderator}

@Entity
@Table(name = "employee")
data class Employee(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    val id: Int,
    val username: String,
    val name: String,
    val email: String,
    val phone: String,
    val password: String,
    val role: Position
)
@Entity
@Table(name = 'user")
    data class User(
        @Id
        @GeneratedValue(strategy = GenerationType.IDENTITY)
        val id = Int,
        val username = String,
        val email = String,
        val phone = String,
        val password = String,
        val birthday: LocalDate,
        val pfp: Int,
        val gender: Boolean,
        val topics: List <Int>
    )


@Entity
@Table(name = "students")
dete class Student(
    @Id
    @ @GeneratedValue(strategy = GenerationType.IDENTITY)
    val id : Int,
    val name : String,
    val surname: String,
    val birthday: String,
    val gender: Boolean,
    val phone: String,
    val email: String,
    val name_parents: String,

)

@Entity
@Table(name = "shool")
data class Entry(
    @Id,
    @GeneratedValue(strategy = Generation.Type.IDENTITY)
    val id: Int,
    val posted: LocalDataTime,
    val content: String,
    val moderation: Boolean,
    val topics: List<Int>
    for auto range by the cooner to be more responsobles and niced we n
)

@Entity 
@Table (name = "teacher")
data class Teacher(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    val id: Int, 
    val iduser : Int, 
    val posted: Int, 
    val host: String,
    
)

@Entity
@Table(name = "entries")
data class Entry(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    val id: Int,
    val iduser: Int,
    val posted: LocalDateTime,
    val content: String,
    val moderated: Boolean,
    val public: Boolean,
    val topics: List<Int>

)
