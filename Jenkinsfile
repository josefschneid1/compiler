pipeline {
    agent any

    stages {

         stage('Initialize'){
            steps{

            def dockerHome = tool 'myDocker'
            env.PATH = "${dockerHome}/bin:${env.PATH}"                    
            }
         }
        stage('Build Image') {
            steps{
                sh 'docker build . -t image'
            }
        }
        stage('Build Application') {
            steps
            {
             sh 'docker run -v .:/src image sh -c "conan build ."'

            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        } 
    }
}