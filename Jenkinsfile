pipeline {
    agent any
    stages {

         stage('Checkout') {
            steps {
                checkout scm
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
             sh 'ls -lah ${WORKSPACE}'
             sh """
                 docker run -v ${WORKSPACE}:/src image sh -c "ls -lah"    
                """

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